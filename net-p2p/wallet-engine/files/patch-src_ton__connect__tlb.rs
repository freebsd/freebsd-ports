--- src/ton_connect_tlb.rs.orig	2026-10-09 11:27:19 UTC
+++ src/ton_connect_tlb.rs
@@ -0,0 +1,2804 @@
+//! TL-B display decoding of TON Connect `signData` cells.
+//!
+//! A `signData` request of type `cell` carries a one-root cell `BoC` and the
+//! TL-B schema that describes it; the schema's last declaration is the root.
+//! [`decode_sign_data_cell`] interprets a bounded subset of TL-B, reads the
+//! cell with exactly that declaration (its tag must match; other constructors
+//! of the same type serve only nested uses of the type) and lists its fields in
+//! cell order for display. Both inputs come from the dApp:
+//! every size is checked before a read or an allocation, parsing and decoding
+//! are bounded in nesting, work and output, and any failure discards the
+//! partial result. Signing never depends on the decoding.
+//!
+//! Supported: constructor tags `#hex`, `#hex_`, `#_`, `$bits`, `$_` and a bare
+//! `_` constructor; fields `name:Type`, `_:Type`, anonymous types and
+//! `^[ … ]` cells; conditional fields `flag?Type` and `(flag . bit)?Type`;
+//! `{ a op b }` constraints over `+` and `*`; `{n:#}` and `{X:Type}`
+//! parameters; `#`, `## n`, `#< n`, `#<= n`, `uintN`, `intN`, `bitsN` and
+//! their applied forms; `Bool`, `Maybe`, `Either`, `Both`, `VarUInteger`,
+//! `VarInteger`, `Coins`, `Grams`, `MsgAddress`, `MsgAddressInt`,
+//! `MsgAddressExt`, `Cell`, `Any`, `^Type`; and every type the schema itself
+//! declares, which shadows a builtin of the same name.
+
+use std::collections::HashSet;
+use std::rc::Rc;
+
+use num_bigint::{BigInt, BigUint};
+use ton::ton_core::cell::{BoC, CellParser, TonCell};
+use ton::ton_core::traits::tlb::TLB as _;
+use ton_connect_core::{CellBoc, FriendlyAddress, RawAccountAddress};
+
+/// One decoded field of a `signData` cell.
+#[derive(Debug, Clone, PartialEq, Eq, uniffi::Record)]
+pub struct TonConnectSignDataCellField {
+    /// Nesting level: 0 for the root's fields; entries after a structure entry
+    /// with a greater depth are its sub-fields.
+    pub depth: u32,
+    /// The field name exactly as the schema names it (`_` when unnamed).
+    pub name: String,
+    /// The display value; for a structure, its constructor name (empty for `_`).
+    pub value: String,
+}
+
+/// Why a `signData` cell could not be decoded by its schema.
+#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, uniffi::Enum)]
+pub enum TonConnectSignDataCellFailure {
+    /// The schema is not valid TL-B text.
+    InvalidSchema,
+    /// The schema uses a construct the decoder does not support.
+    UnsupportedSchema,
+    /// The cell is not a valid one-root `BoC` or contains an exotic cell.
+    InvalidCell,
+    /// No constructor tag of a type matches the cell.
+    TagMismatch,
+    /// A `{ … }` constraint or a `#<`/`#<=` bound does not hold.
+    ConstraintViolated,
+    /// Bits or references remain after the schema is fully read.
+    TrailingData,
+    /// The cell ends before the schema is fully read.
+    TruncatedCell,
+    /// A size, nesting, work, or output bound was exceeded.
+    LimitExceeded,
+}
+
+/// The result of decoding a `signData` cell by its TL-B schema.
+#[derive(Debug, Clone, PartialEq, Eq, uniffi::Enum)]
+pub enum TonConnectSignDataCellDecoding {
+    /// The cell matches the schema exactly.
+    Decoded {
+        /// The root declaration's fields in cell order.
+        fields: Vec<TonConnectSignDataCellField>,
+    },
+    /// The cell cannot be shown by its schema; no field is reported.
+    NotDecodable {
+        /// The typed reason.
+        failure: TonConnectSignDataCellFailure,
+        /// A short diagnostic for logs; it echoes at most 32 characters of input.
+        detail: String,
+    },
+}
+
+/// Longest accepted schema text in bytes, checked before lexing.
+const MAX_SCHEMA_BYTES: usize = 16_384;
+/// Most tokens one schema may contain.
+const MAX_TOKENS: usize = 4_096;
+/// Most declarations one schema may contain.
+const MAX_DECLARATIONS: usize = 128;
+/// Most parameters, fields, and constraints one declaration may contain.
+const MAX_FIELDS_PER_DECLARATION: usize = 64;
+/// Deepest nesting of parentheses, brackets, references, and operators in the schema text.
+const MAX_PARSE_NESTING: usize = 32;
+/// Deepest nesting of type instantiations while decoding.
+const MAX_DECODE_DEPTH: u32 = 32;
+/// Decoding steps one call may take (fields, types, constructor probes).
+const MAX_STEPS: u32 = 20_000;
+/// Most entries one result may contain.
+const MAX_FIELDS: usize = 256;
+/// Most bytes of names and values one result may contain.
+const MAX_OUTPUT_BYTES: usize = 32_768;
+/// Most distinct cells one `Cell`/`Any` value may contain, checked before it is serialized.
+const MAX_CELL_VALUE_CELLS: usize = 256;
+/// Longest constructor tag in bits.
+const MAX_TAG_BITS: usize = 64;
+/// Widest `uint` in bits.
+const MAX_UINT_BITS: u64 = 256;
+/// Widest `int` in bits.
+const MAX_INT_BITS: u64 = 257;
+/// Longest constant `bits` width; a cell holds at most 1023 data bits.
+const MAX_BITS: u64 = 1023;
+/// Widest `## n` in bits.
+const MAX_NAT_BITS: u64 = 64;
+/// Largest `n` of `VarUInteger n` and `VarInteger n`.
+const MAX_VAR_INTEGER_BYTES: u64 = 32;
+/// Most input characters one diagnostic echoes.
+const DETAIL_ECHO_CHARS: usize = 32;
+
+/// Decodes a `signData` cell by the last declaration of its TL-B schema.
+///
+/// `schema` and `cell` are the strings of a `cell` payload exactly as received;
+/// `testnet` selects the test-only flag of friendly addresses. The result is
+/// the full field list or a typed failure, never a partial list.
+pub(crate) fn decode_sign_data_cell(
+    schema: &str,
+    cell: &str,
+    testnet: bool,
+) -> TonConnectSignDataCellDecoding {
+    match decode(schema, cell, testnet) {
+        Ok(fields) => TonConnectSignDataCellDecoding::Decoded { fields },
+        Err(Failure { kind, detail }) => TonConnectSignDataCellDecoding::NotDecodable {
+            failure: kind,
+            detail,
+        },
+    }
+}
+
+fn decode(schema: &str, cell: &str, testnet: bool) -> Outcome<Vec<TonConnectSignDataCellField>> {
+    if schema.len() > MAX_SCHEMA_BYTES {
+        return Err(limit("schema is longer than 16384 bytes"));
+    }
+    let tokens = tokenize(schema)?;
+    let schema = parse_schema(&tokens)?;
+    let boc = CellBoc::try_from(cell).map_err(|_| invalid_cell("cell is not a one-root BoC"))?;
+    let root = TonCell::from_boc(boc.as_bytes().to_vec())
+        .map_err(|_| invalid_cell("cell is not a one-root BoC"))?;
+    if root.cell_type().is_exotic() {
+        return Err(invalid_cell("exotic cells are not decodable"));
+    }
+    let mut decoder = Decoder {
+        schema: &schema,
+        testnet,
+        steps: 0,
+        output: Vec::new(),
+        output_bytes: 0,
+    };
+    let mut parser = root.parser();
+    let root = schema.root()?;
+    let _ = decoder.decode_constructor(
+        &mut parser,
+        root,
+        &[],
+        &Env::default(),
+        Place {
+            name: "",
+            depth: 0,
+            level: 0,
+        },
+        false,
+    )?;
+    ensure_empty(&mut parser)?;
+    Ok(decoder.output)
+}
+
+/// An internal decoding failure; it becomes `NotDecodable`.
+#[derive(Debug)]
+struct Failure {
+    kind: TonConnectSignDataCellFailure,
+    detail: String,
+}
+
+type Outcome<T> = Result<T, Failure>;
+
+fn failure(kind: TonConnectSignDataCellFailure, detail: impl Into<String>) -> Failure {
+    Failure {
+        kind,
+        detail: detail.into(),
+    }
+}
+
+fn invalid(detail: impl Into<String>) -> Failure {
+    failure(TonConnectSignDataCellFailure::InvalidSchema, detail)
+}
+
+fn unsupported(detail: impl Into<String>) -> Failure {
+    failure(TonConnectSignDataCellFailure::UnsupportedSchema, detail)
+}
+
+fn invalid_cell(detail: impl Into<String>) -> Failure {
+    failure(TonConnectSignDataCellFailure::InvalidCell, detail)
+}
+
+fn truncated(detail: impl Into<String>) -> Failure {
+    failure(TonConnectSignDataCellFailure::TruncatedCell, detail)
+}
+
+fn limit(detail: impl Into<String>) -> Failure {
+    failure(TonConnectSignDataCellFailure::LimitExceeded, detail)
+}
+
+fn tag_mismatch(type_name: &str) -> Failure {
+    failure(
+        TonConnectSignDataCellFailure::TagMismatch,
+        format!("tag mismatch in {:?}", echo(type_name)),
+    )
+}
+
+fn truncated_tag(type_name: &str) -> Failure {
+    truncated(format!("cell ends before a tag of {:?}", echo(type_name)))
+}
+
+/// At most `DETAIL_ECHO_CHARS` characters of untrusted input for a diagnostic.
+fn echo(text: &str) -> String {
+    text.chars().take(DETAIL_ECHO_CHARS).collect()
+}
+
+// ---------------------------------------------------------------------------
+// Lexer
+// ---------------------------------------------------------------------------
+
+/// A constructor tag: `len` bits holding `bits`.
+#[derive(Debug, Clone, Copy, PartialEq, Eq)]
+struct Tag {
+    bits: u64,
+    len: usize,
+}
+
+#[derive(Debug, Clone, PartialEq, Eq)]
+enum Token {
+    Ident(String),
+    Number(u64),
+    /// A constructor tag written directly after a constructor name.
+    Tag(Tag),
+    Colon,
+    Semicolon,
+    Equals,
+    LeftParen,
+    RightParen,
+    LeftBracket,
+    RightBracket,
+    LeftBrace,
+    RightBrace,
+    Caret,
+    Tilde,
+    Question,
+    Dot,
+    Plus,
+    Star,
+    Bang,
+    Less,
+    LessEq,
+    Greater,
+    GreaterEq,
+    Hash,
+    HashHash,
+    HashLess,
+    HashLessEq,
+}
+
+fn tokenize(schema: &str) -> Outcome<Vec<Token>> {
+    let mut lexer = Lexer {
+        chars: schema.chars().collect(),
+        position: 0,
+        tokens: Vec::new(),
+    };
+    lexer.run()?;
+    Ok(lexer.tokens)
+}
+
+struct Lexer {
+    chars: Vec<char>,
+    position: usize,
+    tokens: Vec<Token>,
+}
+
+impl Lexer {
+    fn peek(&self, offset: usize) -> Option<char> {
+        self.position
+            .checked_add(offset)
+            .and_then(|index| self.chars.get(index).copied())
+    }
+
+    const fn bump(&mut self) {
+        self.position = self.position.saturating_add(1);
+    }
+
+    fn push(&mut self, token: Token) -> Outcome<()> {
+        if self.tokens.len() >= MAX_TOKENS {
+            return Err(limit("schema has more than 4096 tokens"));
+        }
+        self.tokens.push(token);
+        Ok(())
+    }
+
+    fn run(&mut self) -> Outcome<()> {
+        while let Some(current) = self.peek(0) {
+            if current.is_whitespace() {
+                self.bump();
+            } else if current == '/' {
+                self.comment()?;
+            } else if current.is_ascii_alphabetic() || current == '_' {
+                self.identifier()?;
+            } else if current.is_ascii_digit() {
+                self.number()?;
+            } else {
+                self.punctuation(current)?;
+            }
+        }
+        Ok(())
+    }
+
+    fn comment(&mut self) -> Outcome<()> {
+        match self.peek(1) {
+            Some('/') => {
+                while let Some(current) = self.peek(0) {
+                    self.bump();
+                    if current == '\n' {
+                        break;
+                    }
+                }
+                Ok(())
+            }
+            Some('*') => {
+                self.bump();
+                self.bump();
+                loop {
+                    match (self.peek(0), self.peek(1)) {
+                        (Some('*'), Some('/')) => {
+                            self.bump();
+                            self.bump();
+                            return Ok(());
+                        }
+                        (Some(_), _) => self.bump(),
+                        (None, _) => return Err(invalid("unterminated comment")),
+                    }
+                }
+            }
+            Some(_) | None => Err(invalid("unexpected '/'")),
+        }
+    }
+
+    fn identifier(&mut self) -> Outcome<()> {
+        let mut name = String::new();
+        while let Some(current) = self.peek(0) {
+            if !current.is_ascii_alphanumeric() && current != '_' {
+                break;
+            }
+            name.push(current);
+            self.bump();
+        }
+        self.push(Token::Ident(name))?;
+        match self.peek(0) {
+            Some('#') => self.hex_tag(),
+            Some('$') => self.binary_tag(),
+            Some(_) | None => Ok(()),
+        }
+    }
+
+    /// `#hex`, `#hex_` (completion tag) or `#_`, directly after a name.
+    fn hex_tag(&mut self) -> Outcome<()> {
+        self.bump();
+        let mut bits = 0_u64;
+        let mut len = 0_usize;
+        while let Some(digit) = self.peek(0).and_then(|current| current.to_digit(16)) {
+            len = len
+                .checked_add(4)
+                .filter(|len| *len <= MAX_TAG_BITS)
+                .ok_or_else(|| unsupported("constructor tag is longer than 64 bits"))?;
+            bits = bits.wrapping_shl(4) | u64::from(digit);
+            self.bump();
+        }
+        let completion = self.peek(0) == Some('_');
+        if completion {
+            self.bump();
+        } else if len == 0 {
+            return Err(unsupported("implicit constructor tags are not supported"));
+        }
+        if completion && len > 0 {
+            if bits == 0 {
+                return Err(invalid("completion tag has no end bit"));
+            }
+            let strip = bits.trailing_zeros().saturating_add(1);
+            bits = bits.checked_shr(strip).unwrap_or(0);
+            len = usize::try_from(strip)
+                .ok()
+                .and_then(|strip| len.checked_sub(strip))
+                .ok_or_else(|| invalid("completion tag has no end bit"))?;
+        }
+        self.push(Token::Tag(Tag { bits, len }))
+    }
+
+    /// `$bits` or `$_`, directly after a name.
+    fn binary_tag(&mut self) -> Outcome<()> {
+        self.bump();
+        if self.peek(0) == Some('_') {
+            self.bump();
+            return self.push(Token::Tag(Tag { bits: 0, len: 0 }));
+        }
+        let mut bits = 0_u64;
+        let mut len = 0_usize;
+        while let Some(digit) = self.peek(0).and_then(|current| current.to_digit(2)) {
+            len = len
+                .checked_add(1)
+                .filter(|len| *len <= MAX_TAG_BITS)
+                .ok_or_else(|| unsupported("constructor tag is longer than 64 bits"))?;
+            bits = bits.wrapping_shl(1) | u64::from(digit);
+            self.bump();
+        }
+        if len == 0 {
+            return Err(invalid("'$' must be followed by binary digits or '_'"));
+        }
+        self.push(Token::Tag(Tag { bits, len }))
+    }
+
+    fn number(&mut self) -> Outcome<()> {
+        let mut value = 0_u64;
+        while let Some(digit) = self.peek(0).and_then(|current| current.to_digit(10)) {
+            value = value
+                .checked_mul(10)
+                .and_then(|value| value.checked_add(u64::from(digit)))
+                .ok_or_else(|| limit("number in schema is too large"))?;
+            self.bump();
+        }
+        self.push(Token::Number(value))
+    }
+
+    fn punctuation(&mut self, current: char) -> Outcome<()> {
+        let next = self.peek(1);
+        let (token, width) = match current {
+            ':' => (Token::Colon, 1),
+            ';' => (Token::Semicolon, 1),
+            '=' => (Token::Equals, 1),
+            '(' => (Token::LeftParen, 1),
+            ')' => (Token::RightParen, 1),
+            '[' => (Token::LeftBracket, 1),
+            ']' => (Token::RightBracket, 1),
+            '{' => (Token::LeftBrace, 1),
+            '}' => (Token::RightBrace, 1),
+            '^' => (Token::Caret, 1),
+            '~' => (Token::Tilde, 1),
+            '?' => (Token::Question, 1),
+            '.' => (Token::Dot, 1),
+            '+' => (Token::Plus, 1),
+            '*' => (Token::Star, 1),
+            '!' => (Token::Bang, 1),
+            '<' if next == Some('=') => (Token::LessEq, 2),
+            '<' => (Token::Less, 1),
+            '>' if next == Some('=') => (Token::GreaterEq, 2),
+            '>' => (Token::Greater, 1),
+            '#' if next == Some('#') => (Token::HashHash, 2),
+            '#' if next == Some('<') && self.peek(2) == Some('=') => (Token::HashLessEq, 3),
+            '#' if next == Some('<') => (Token::HashLess, 2),
+            '#' => (Token::Hash, 1),
+            other => return Err(invalid(format!("unexpected character {other:?}"))),
+        };
+        for _ in 0..width {
+            self.bump();
+        }
+        self.push(token)
+    }
+}
+
+// ---------------------------------------------------------------------------
+// Schema
+// ---------------------------------------------------------------------------
+
+struct Schema {
+    /// Never empty; the last one is the root.
+    declarations: Vec<Declaration>,
+}
+
+impl Schema {
+    /// The root: exactly the last declaration, not every constructor of its type.
+    fn root(&self) -> Outcome<&Declaration> {
+        self.declarations
+            .last()
+            .ok_or_else(|| invalid("schema has no declarations"))
+    }
+
+    fn declares(&self, name: &str) -> bool {
+        self.declarations
+            .iter()
+            .any(|declaration| declaration.result == name)
+    }
+}
+
+struct Declaration {
+    constructor: String,
+    tag: Tag,
+    params: Vec<Param>,
+    items: Vec<Item>,
+    result: String,
+}
+
+#[derive(Debug, Clone, Copy, PartialEq, Eq)]
+enum ParamKind {
+    Nat,
+    Type,
+}
+
+struct Param {
+    name: String,
+    kind: ParamKind,
+}
+
+enum Item {
+    Field(Field),
+    Constraint(Constraint),
+    /// An anonymous `^[ … ]` cell whose fields belong to the enclosing level.
+    Inline(Vec<Item>),
+}
+
+struct Field {
+    name: String,
+    condition: Option<Condition>,
+    ty: TypeExpr,
+}
+
+/// `flag?T` (`bit` is `None`) or `(flag . bit)?T`.
+struct Condition {
+    flag: String,
+    bit: Option<u32>,
+}
+
+struct Constraint {
+    left: NatExpr,
+    relation: Relation,
+    right: NatExpr,
+}
+
+#[derive(Debug, Clone, Copy, PartialEq, Eq)]
+enum Relation {
+    Equal,
+    Less,
+    LessEqual,
+    Greater,
+    GreaterEqual,
+}
+
+#[derive(Debug, Clone, Copy, PartialEq, Eq)]
+enum SizedKind {
+    /// `uint n`, `uintN`, `#`.
+    Uint,
+    /// `int n`, `intN`.
+    Int,
+    /// `bits n`, `bitsN`.
+    Bits,
+    /// `## n`.
+    NatBits,
+    /// `#< n`.
+    NatLess,
+    /// `#<= n`.
+    NatLessEqual,
+}
+
+enum TypeExpr {
+    Named(String, Vec<Arg>),
+    Ref(Box<TypeExpr>),
+    /// A named field's `^[ … ]` cell.
+    InlineCell(Vec<Item>),
+    Sized(SizedKind, NatExpr),
+}
+
+enum Arg {
+    Type(TypeExpr),
+    Nat(NatExpr),
+}
+
+enum NatExpr {
+    Const(u64),
+    Var(String),
+    Add(Box<NatExpr>, Box<NatExpr>),
+    Mul(Box<NatExpr>, Box<NatExpr>),
+}
+
+/// Rejects widths the decoder cannot read; `constant` widths of `bits` must fit a cell.
+fn check_width(kind: SizedKind, width: u64, constant: bool) -> Outcome<()> {
+    let supported = match kind {
+        SizedKind::Uint => width <= MAX_UINT_BITS,
+        SizedKind::Int => (1..=MAX_INT_BITS).contains(&width),
+        SizedKind::Bits => !constant || width <= MAX_BITS,
+        SizedKind::NatBits => width <= MAX_NAT_BITS,
+        SizedKind::NatLess => width > 0,
+        SizedKind::NatLessEqual => true,
+    };
+    if supported {
+        Ok(())
+    } else {
+        Err(unsupported(format!("unsupported width {width}")))
+    }
+}
+
+/// `uintN`, `intN` and `bitsN` names.
+fn sized_name(name: &str) -> Outcome<Option<(SizedKind, u64)>> {
+    for (prefix, kind) in [
+        ("uint", SizedKind::Uint),
+        ("int", SizedKind::Int),
+        ("bits", SizedKind::Bits),
+    ] {
+        let Some(digits) = name.strip_prefix(prefix) else {
+            continue;
+        };
+        if digits.is_empty() || !digits.bytes().all(|byte| byte.is_ascii_digit()) {
+            continue;
+        }
+        let width = digits
+            .parse::<u64>()
+            .map_err(|_| unsupported(format!("unsupported type {:?}", echo(name))))?;
+        check_width(kind, width, true)?;
+        return Ok(Some((kind, width)));
+    }
+    Ok(None)
+}
+
+fn parse_schema(tokens: &[Token]) -> Outcome<Schema> {
+    let mut parser = Parser {
+        tokens,
+        position: 0,
+        nesting: 0,
+        items: 0,
+        nat_names: Vec::new(),
+    };
+    let mut declarations = Vec::new();
+    while parser.peek(0).is_some() {
+        if declarations.len() >= MAX_DECLARATIONS {
+            return Err(limit("schema has more than 128 declarations"));
+        }
+        declarations.push(parser.declaration()?);
+    }
+    let schema = Schema { declarations };
+    if !schema.root()?.params.is_empty() {
+        return Err(unsupported("the root type has parameters"));
+    }
+    Ok(schema)
+}
+
+enum Braced {
+    Param(Param),
+    Constraint(Constraint),
+}
+
+struct Parser<'t> {
+    tokens: &'t [Token],
+    position: usize,
+    nesting: usize,
+    /// Items of the current declaration.
+    items: usize,
+    /// Names that denote numbers in the current declaration.
+    nat_names: Vec<&'t str>,
+}
+
+impl<'t> Parser<'t> {
+    fn peek(&self, offset: usize) -> Option<&'t Token> {
+        self.position
+            .checked_add(offset)
+            .and_then(|index| self.tokens.get(index))
+    }
+
+    const fn advance(&mut self, count: usize) {
+        self.position = self.position.saturating_add(count);
+    }
+
+    fn next(&mut self) -> Option<&'t Token> {
+        let token = self.peek(0);
+        if token.is_some() {
+            self.advance(1);
+        }
+        token
+    }
+
+    fn expect(&mut self, expected: &Token, what: &str) -> Outcome<()> {
+        if self.next() == Some(expected) {
+            Ok(())
+        } else {
+            Err(invalid(format!("expected {what}")))
+        }
+    }
+
+    fn enter(&mut self) -> Outcome<()> {
+        self.nesting = self.nesting.saturating_add(1);
+        if self.nesting > MAX_PARSE_NESTING {
+            return Err(limit("schema nesting is deeper than 32"));
+        }
+        Ok(())
+    }
+
+    const fn leave(&mut self) {
+        self.nesting = self.nesting.saturating_sub(1);
+    }
+
+    fn count_item(&mut self) -> Outcome<()> {
+        self.items = self.items.saturating_add(1);
+        if self.items > MAX_FIELDS_PER_DECLARATION {
+            return Err(limit("declaration has more than 64 fields"));
+        }
+        Ok(())
+    }
+
+    fn is_nat_name(&self, name: &str) -> bool {
+        self.nat_names.contains(&name)
+    }
+
+    fn declaration(&mut self) -> Outcome<Declaration> {
+        self.items = 0;
+        self.nat_names.clear();
+        let constructor = match self.next() {
+            Some(Token::Ident(name)) => name.clone(),
+            Some(Token::Bang) => return Err(unsupported("special constructors")),
+            Some(_) | None => return Err(invalid("expected a constructor name")),
+        };
+        let tag = if let Some(Token::Tag(tag)) = self.peek(0) {
+            self.advance(1);
+            *tag
+        } else if constructor == "_" {
+            Tag { bits: 0, len: 0 }
+        } else {
+            return Err(unsupported("implicit constructor tags are not supported"));
+        };
+        let mut params = Vec::new();
+        let items = self.items_until(&Token::Equals, Some(&mut params))?;
+        let result = match self.next() {
+            Some(Token::Ident(name)) => name.clone(),
+            Some(Token::Tilde) => return Err(unsupported("deduced parameters")),
+            Some(_) | None => return Err(invalid("expected a type name after '='")),
+        };
+        let mut result_args = Vec::new();
+        loop {
+            match self.next() {
+                Some(Token::Semicolon) | None => break,
+                Some(Token::Ident(name)) => result_args.push(name.as_str()),
+                Some(Token::Tilde) => return Err(unsupported("deduced parameters")),
+                Some(Token::LeftParen | Token::Number(_) | Token::Plus | Token::Star) => {
+                    return Err(unsupported("computed type arguments"));
+                }
+                Some(_) => return Err(invalid("unexpected token in a type")),
+            }
+        }
+        let declared = params.iter().map(|param: &Param| param.name.as_str());
+        if !result_args.iter().copied().eq(declared) {
+            return Err(unsupported(
+                "type arguments must be the declared parameters in order",
+            ));
+        }
+        Ok(Declaration {
+            constructor,
+            tag,
+            params,
+            items,
+            result,
+        })
+    }
+
+    /// Items up to `end`; `params` is `None` inside a `^[ … ]` cell.
+    fn items_until(
+        &mut self,
+        end: &Token,
+        mut params: Option<&mut Vec<Param>>,
+    ) -> Outcome<Vec<Item>> {
+        let mut items = Vec::new();
+        loop {
+            match self.peek(0) {
+                None => return Err(invalid("declaration is incomplete")),
+                Some(token) if token == end => {
+                    self.advance(1);
+                    return Ok(items);
+                }
+                Some(Token::LeftBrace) => {
+                    self.advance(1);
+                    self.count_item()?;
+                    match self.braced()? {
+                        Braced::Param(param) => {
+                            let Some(params) = params.as_deref_mut() else {
+                                return Err(unsupported("parameters inside a cell"));
+                            };
+                            params.push(param);
+                        }
+                        Braced::Constraint(constraint) => {
+                            items.push(Item::Constraint(constraint));
+                        }
+                    }
+                }
+                Some(_) => {
+                    self.count_item()?;
+                    items.push(self.item()?);
+                }
+            }
+        }
+    }
+
+    /// `{n:#}`, `{X:Type}` or a constraint; the `{` is consumed.
+    fn braced(&mut self) -> Outcome<Braced> {
+        if let (Some(Token::Ident(name)), Some(Token::Colon)) = (self.peek(0), self.peek(1)) {
+            let kind = match self.peek(2) {
+                Some(Token::Hash) => ParamKind::Nat,
+                Some(Token::Ident(kind)) if kind == "Type" => ParamKind::Type,
+                Some(_) | None => return Err(unsupported("unsupported parameter kind")),
+            };
+            self.advance(3);
+            self.expect(&Token::RightBrace, "'}'")?;
+            if kind == ParamKind::Nat {
+                self.nat_names.push(name);
+            }
+            return Ok(Braced::Param(Param {
+                name: name.clone(),
+                kind,
+            }));
+        }
+        let left = self.nat_sum()?;
+        let relation = match self.next() {
+            Some(Token::Equals) => Relation::Equal,
+            Some(Token::Less) => Relation::Less,
+            Some(Token::LessEq) => Relation::LessEqual,
+            Some(Token::Greater) => Relation::Greater,
+            Some(Token::GreaterEq) => Relation::GreaterEqual,
+            Some(Token::Tilde) => return Err(unsupported("deduced parameters")),
+            Some(_) | None => return Err(invalid("expected a comparison")),
+        };
+        let right = self.nat_sum()?;
+        self.expect(&Token::RightBrace, "'}'")?;
+        Ok(Braced::Constraint(Constraint {
+            left,
+            relation,
+            right,
+        }))
+    }
+
+    fn item(&mut self) -> Outcome<Item> {
+        match (self.peek(0), self.peek(1)) {
+            (Some(Token::Ident(name)), Some(Token::Colon)) => {
+                self.advance(2);
+                let condition = self.condition()?;
+                let ty = self.type_term()?;
+                if name != "_" {
+                    self.nat_names.push(name);
+                }
+                Ok(Item::Field(Field {
+                    name: name.clone(),
+                    condition,
+                    ty,
+                }))
+            }
+            (Some(Token::Caret), Some(Token::LeftBracket)) => {
+                self.advance(2);
+                Ok(Item::Inline(self.inline_items()?))
+            }
+            (Some(Token::LeftBracket), _) => Err(unsupported("records without '^'")),
+            (Some(Token::Tilde), _) => Err(unsupported("deduced parameters")),
+            _ => Ok(Item::Field(Field {
+                name: "_".to_owned(),
+                condition: None,
+                ty: self.type_term()?,
+            })),
+        }
+    }
+
+    /// The items of `^[ … ]`; the `^[` is consumed.
+    fn inline_items(&mut self) -> Outcome<Vec<Item>> {
+        self.enter()?;
+        let items = self.items_until(&Token::RightBracket, None);
+        self.leave();
+        items
+    }
+
+    fn condition(&mut self) -> Outcome<Option<Condition>> {
+        if let (Some(Token::Ident(flag)), Some(Token::Question)) = (self.peek(0), self.peek(1)) {
+            self.advance(2);
+            return Ok(Some(Condition {
+                flag: flag.clone(),
+                bit: None,
+            }));
+        }
+        if let (
+            Some(Token::LeftParen),
+            Some(Token::Ident(flag)),
+            Some(Token::Dot),
+            Some(Token::Number(bit)),
+            Some(Token::RightParen),
+            Some(Token::Question),
+        ) = (
+            self.peek(0),
+            self.peek(1),
+            self.peek(2),
+            self.peek(3),
+            self.peek(4),
+            self.peek(5),
+        ) {
+            let bit = u32::try_from(*bit)
+                .ok()
+                .filter(|bit| *bit < u64::BITS)
+                .ok_or_else(|| unsupported("condition bit is above 63"))?;
+            self.advance(6);
+            return Ok(Some(Condition {
+                flag: flag.clone(),
+                bit: Some(bit),
+            }));
+        }
+        Ok(None)
+    }
+
+    fn type_term(&mut self) -> Outcome<TypeExpr> {
+        self.enter()?;
+        let term = self.type_term_inner();
+        self.leave();
+        term
+    }
+
+    fn type_term_inner(&mut self) -> Outcome<TypeExpr> {
+        match self.next() {
+            Some(Token::Caret) => {
+                if self.peek(0) == Some(&Token::LeftBracket) {
+                    self.advance(1);
+                    Ok(TypeExpr::InlineCell(self.inline_items()?))
+                } else {
+                    Ok(TypeExpr::Ref(Box::new(self.type_term()?)))
+                }
+            }
+            Some(Token::LeftParen) => {
+                let term = self.applied()?;
+                self.expect(&Token::RightParen, "')'")?;
+                Ok(term)
+            }
+            Some(Token::Hash) => Ok(TypeExpr::Sized(SizedKind::Uint, NatExpr::Const(32))),
+            Some(Token::HashHash) => self.sized(SizedKind::NatBits, false),
+            Some(Token::HashLess) => self.sized(SizedKind::NatLess, false),
+            Some(Token::HashLessEq) => self.sized(SizedKind::NatLessEqual, false),
+            Some(Token::Ident(name)) => Ok(match sized_name(name)? {
+                Some((kind, width)) => TypeExpr::Sized(kind, NatExpr::Const(width)),
+                None => TypeExpr::Named(name.clone(), Vec::new()),
+            }),
+            Some(Token::LeftBracket) => Err(unsupported("records without '^'")),
+            Some(Token::Tilde) => Err(unsupported("deduced parameters")),
+            Some(_) | None => Err(invalid("expected a type")),
+        }
+    }
+
+    /// A sized builtin; `whole` takes the whole expression up to `)`.
+    fn sized(&mut self, kind: SizedKind, whole: bool) -> Outcome<TypeExpr> {
+        let width = if whole {
+            self.nat_sum()?
+        } else {
+            self.nat_primary()?
+        };
+        if let NatExpr::Const(width) = width {
+            check_width(kind, width, true)?;
+        }
+        Ok(TypeExpr::Sized(kind, width))
+    }
+
+    /// The inside of `( … )`; the `(` is consumed.
+    fn applied(&mut self) -> Outcome<TypeExpr> {
+        match (self.peek(0), self.peek(1)) {
+            (Some(Token::HashHash), _) => {
+                self.advance(1);
+                return self.sized(SizedKind::NatBits, true);
+            }
+            (Some(Token::HashLess), _) => {
+                self.advance(1);
+                return self.sized(SizedKind::NatLess, true);
+            }
+            (Some(Token::HashLessEq), _) => {
+                self.advance(1);
+                return self.sized(SizedKind::NatLessEqual, true);
+            }
+            (Some(Token::Ident(head)), Some(next))
+                if matches!(head.as_str(), "uint" | "int" | "bits")
+                    && next != &Token::RightParen =>
+            {
+                let kind = match head.as_str() {
+                    "uint" => SizedKind::Uint,
+                    "int" => SizedKind::Int,
+                    _ => SizedKind::Bits,
+                };
+                self.advance(1);
+                return self.sized(kind, true);
+            }
+            (Some(Token::Number(_)), _) | (Some(Token::Ident(_)), Some(Token::Star)) => {
+                return Err(unsupported("tuples"));
+            }
+            _ => {}
+        }
+        let head = self.type_term()?;
+        let mut args = Vec::new();
+        while !matches!(self.peek(0), Some(Token::RightParen) | None) {
+            if args.len() >= MAX_FIELDS_PER_DECLARATION {
+                return Err(limit("type has more than 64 arguments"));
+            }
+            args.push(self.arg()?);
+        }
+        if args.is_empty() {
+            return Ok(head);
+        }
+        if let TypeExpr::Named(name, existing) = head
+            && existing.is_empty()
+        {
+            return Ok(TypeExpr::Named(name, args));
+        }
+        Err(invalid("only a type name takes arguments"))
+    }
+
+    fn arg(&mut self) -> Outcome<Arg> {
+        match self.peek(0) {
+            Some(Token::Number(_)) => Ok(Arg::Nat(self.nat_primary()?)),
+            Some(Token::Ident(name)) if self.is_nat_name(name) => Ok(Arg::Nat(self.nat_primary()?)),
+            Some(Token::LeftParen) if self.parenthesized_nat() => Ok(Arg::Nat(self.nat_primary()?)),
+            Some(_) | None => Ok(Arg::Type(self.type_term()?)),
+        }
+    }
+
+    /// Whether the parenthesized argument at the cursor is arithmetic.
+    fn parenthesized_nat(&self) -> bool {
+        let mut offset = 0_usize;
+        while self.peek(offset) == Some(&Token::LeftParen) {
+            offset = offset.saturating_add(1);
+        }
+        match self.peek(offset) {
+            Some(Token::Number(_)) => true,
+            Some(Token::Ident(name)) if self.is_nat_name(name) => matches!(
+                self.peek(offset.saturating_add(1)),
+                Some(Token::Plus | Token::Star | Token::RightParen)
+            ),
+            Some(_) | None => false,
+        }
+    }
+
+    fn nat_sum(&mut self) -> Outcome<NatExpr> {
+        self.nat_chain(&Token::Plus)
+    }
+
+    fn nat_product(&mut self) -> Outcome<NatExpr> {
+        self.nat_chain(&Token::Star)
+    }
+
+    /// A left-associative chain; every operator counts as one nesting level.
+    fn nat_chain(&mut self, operator: &Token) -> Outcome<NatExpr> {
+        let operand = |parser: &mut Self| {
+            if operator == &Token::Plus {
+                parser.nat_product()
+            } else {
+                parser.nat_primary()
+            }
+        };
+        let mut left = operand(self)?;
+        let mut entered = 0_usize;
+        let mut result = Ok(());
+        while self.peek(0) == Some(operator) {
+            self.advance(1);
+            if let Err(error) = self.enter() {
+                result = Err(error);
+                entered = entered.saturating_add(1);
+                break;
+            }
+            entered = entered.saturating_add(1);
+            match operand(self) {
+                Ok(right) => {
+                    left = if operator == &Token::Plus {
+                        NatExpr::Add(Box::new(left), Box::new(right))
+                    } else {
+                        NatExpr::Mul(Box::new(left), Box::new(right))
+                    };
+                }
+                Err(error) => {
+                    result = Err(error);
+                    break;
+                }
+            }
+        }
+        for _ in 0..entered {
+            self.leave();
+        }
+        result.map(|()| left)
+    }
+
+    fn nat_primary(&mut self) -> Outcome<NatExpr> {
+        self.enter()?;
+        let primary = match self.next() {
+            Some(Token::Number(value)) => Ok(NatExpr::Const(*value)),
+            Some(Token::Ident(name)) => Ok(NatExpr::Var(name.clone())),
+            Some(Token::LeftParen) => self
+                .nat_sum()
+                .and_then(|sum| self.expect(&Token::RightParen, "')'").map(|()| sum)),
+            Some(Token::Tilde) => Err(unsupported("deduced parameters")),
+            Some(_) | None => Err(invalid("expected a number or a name")),
+        };
+        self.leave();
+        primary
+    }
+}
+
+// ---------------------------------------------------------------------------
+// Decoder
+// ---------------------------------------------------------------------------
+
+/// A type argument bound to a parameter, with the environment it is read in.
+#[derive(Clone)]
+struct Bound<'s> {
+    ty: &'s TypeExpr,
+    env: Rc<Env<'s>>,
+}
+
+/// Numbers and types visible to one constructor instance.
+#[derive(Clone, Default)]
+struct Env<'s> {
+    nats: Vec<(&'s str, u64)>,
+    types: Vec<(&'s str, Bound<'s>)>,
+}
+
+impl<'s> Env<'s> {
+    fn nat(&self, name: &str) -> Option<u64> {
+        self.nats
+            .iter()
+            .rev()
+            .find(|(known, _)| *known == name)
+            .map(|(_, value)| *value)
+    }
+
+    fn ty(&self, name: &str) -> Option<&Bound<'s>> {
+        self.types
+            .iter()
+            .rev()
+            .find(|(known, _)| *known == name)
+            .map(|(_, bound)| bound)
+    }
+
+    fn eval(&self, expr: &NatExpr) -> Outcome<u64> {
+        match expr {
+            NatExpr::Const(value) => Ok(*value),
+            NatExpr::Var(name) => self
+                .nat(name)
+                .ok_or_else(|| unsupported(format!("{:?} is not a bound number", echo(name)))),
+            NatExpr::Add(left, right) => self
+                .eval(left)?
+                .checked_add(self.eval(right)?)
+                .ok_or_else(|| unsupported("arithmetic overflow")),
+            NatExpr::Mul(left, right) => self
+                .eval(left)?
+                .checked_mul(self.eval(right)?)
+                .ok_or_else(|| unsupported("arithmetic overflow")),
+        }
+    }
+}
+
+/// Where a decoded value goes: its name, its display depth and its decode nesting.
+#[derive(Clone, Copy)]
+struct Place<'n> {
+    name: &'n str,
+    depth: u32,
+    level: u32,
+}
+
+impl<'n> Place<'n> {
+    /// The same entry one decode level deeper.
+    const fn deeper(self) -> Self {
+        Place {
+            level: self.level.saturating_add(1),
+            ..self
+        }
+    }
+
+    /// A sub-field of this entry.
+    const fn child(self, name: &'n str) -> Self {
+        Place {
+            name,
+            depth: self.depth.saturating_add(1),
+            level: self.level.saturating_add(1),
+        }
+    }
+}
+
+/// Which `MsgAddress` constructors a type admits.
+#[derive(Debug, Clone, Copy, PartialEq, Eq)]
+enum AddressKinds {
+    Any,
+    Internal,
+    External,
+}
+
+struct Decoder<'s> {
+    schema: &'s Schema,
+    testnet: bool,
+    steps: u32,
+    output: Vec<TonConnectSignDataCellField>,
+    output_bytes: usize,
+}
+
+impl<'s> Decoder<'s> {
+    fn step(&mut self) -> Outcome<()> {
+        self.steps = self.steps.saturating_add(1);
+        if self.steps > MAX_STEPS {
+            return Err(limit("decoding takes more than 20000 steps"));
+        }
+        Ok(())
+    }
+
+    fn ensure_room(&self, bytes: usize) -> Outcome<()> {
+        if self.output.len() >= MAX_FIELDS {
+            return Err(limit("result has more than 256 fields"));
+        }
+        if self
+            .output_bytes
+            .checked_add(bytes)
+            .is_none_or(|total| total > MAX_OUTPUT_BYTES)
+        {
+            return Err(limit("result is longer than 32768 bytes"));
+        }
+        Ok(())
+    }
+
+    fn push(&mut self, place: Place<'_>, value: String) -> Outcome<()> {
+        let bytes = place.name.len().saturating_add(value.len());
+        self.ensure_room(bytes)?;
+        self.output_bytes = self.output_bytes.saturating_add(bytes);
+        self.output.push(TonConnectSignDataCellField {
+            depth: place.depth,
+            name: place.name.to_owned(),
+            value,
+        });
+        Ok(())
+    }
+
+    /// Decodes one value of `ty`; returns its number when it binds one.
+    fn decode_type(
+        &mut self,
+        parser: &mut CellParser<'_>,
+        ty: &'s TypeExpr,
+        env: &Env<'s>,
+        place: Place<'_>,
+    ) -> Outcome<Option<u64>> {
+        self.step()?;
+        if place.level > MAX_DECODE_DEPTH {
+            return Err(limit("cell nesting is deeper than 32"));
+        }
+        match ty {
+            TypeExpr::Sized(kind, width) => {
+                let width = env.eval(width)?;
+                self.decode_sized(parser, *kind, width, place)
+            }
+            TypeExpr::Ref(inner) => {
+                let child = next_ref(parser)?;
+                let mut child_parser = child.parser();
+                let value = self.decode_type(&mut child_parser, inner, env, place.deeper())?;
+                ensure_empty(&mut child_parser)?;
+                Ok(value)
+            }
+            TypeExpr::InlineCell(items) => {
+                self.push(place, String::new())?;
+                let child = next_ref(parser)?;
+                let mut child_parser = child.parser();
+                let mut scope = env.clone();
+                self.decode_items(&mut child_parser, items, &mut scope, "_", place.child(""))?;
+                ensure_empty(&mut child_parser)?;
+                Ok(None)
+            }
+            TypeExpr::Named(name, args) => {
+                if args.is_empty()
+                    && let Some(bound) = env.ty(name)
+                {
+                    let bound = bound.clone();
+                    return self.decode_type(parser, bound.ty, &bound.env, place.deeper());
+                }
+                if self.schema.declares(name) {
+                    return self.decode_declared(parser, name, args, env, place, true);
+                }
+                self.decode_builtin(parser, name, args, env, place)
+            }
+        }
+    }
+
+    /// Decodes a schema-declared type; `emit` pushes its structure entry.
+    fn decode_declared(
+        &mut self,
+        parser: &mut CellParser<'_>,
+        type_name: &str,
+        args: &'s [Arg],
+        env: &Env<'s>,
+        place: Place<'_>,
+        emit: bool,
+    ) -> Outcome<Option<u64>> {
+        let bits_left = bits_left(parser)?;
+        let mut chosen = None;
+        let mut fits = false;
+        for declaration in &self.schema.declarations {
+            if declaration.result != type_name {
+                continue;
+            }
+            self.step()?;
+            if declaration.tag.len > bits_left {
+                continue;
+            }
+            fits = true;
+            let mut probe = parser.clone();
+            if read_u64(&mut probe, declaration.tag.len)? != declaration.tag.bits {
+                continue;
+            }
+            if chosen.is_some() {
+                return Err(unsupported(format!(
+                    "ambiguous constructor tags in {:?}",
+                    echo(type_name)
+                )));
+            }
+            chosen = Some(declaration);
+        }
+        let Some(declaration) = chosen else {
+            return Err(if fits {
+                tag_mismatch(type_name)
+            } else {
+                truncated_tag(type_name)
+            });
+        };
+        self.decode_constructor(parser, declaration, args, env, place, emit)
+    }
+
+    /// Reads the tag of `declaration`, then its items; `emit` pushes its structure entry.
+    fn decode_constructor(
+        &mut self,
+        parser: &mut CellParser<'_>,
+        declaration: &'s Declaration,
+        args: &'s [Arg],
+        env: &Env<'s>,
+        place: Place<'_>,
+        emit: bool,
+    ) -> Outcome<Option<u64>> {
+        let type_name = declaration.result.as_str();
+        if declaration.tag.len > bits_left(parser)? {
+            return Err(truncated_tag(type_name));
+        }
+        if read_u64(parser, declaration.tag.len)? != declaration.tag.bits {
+            return Err(tag_mismatch(type_name));
+        }
+        if args.len() != declaration.params.len() {
+            return Err(unsupported(format!(
+                "wrong number of arguments for {:?}",
+                echo(type_name)
+            )));
+        }
+        let mut inner = Env::default();
+        let mut captured: Option<Rc<Env<'s>>> = None;
+        for (param, arg) in declaration.params.iter().zip(args) {
+            match (param.kind, arg) {
+                (ParamKind::Nat, Arg::Nat(expr)) => {
+                    inner.nats.push((param.name.as_str(), env.eval(expr)?));
+                }
+                (ParamKind::Type, Arg::Type(ty)) => {
+                    self.step()?;
+                    let env = Rc::clone(captured.get_or_insert_with(|| Rc::new(env.clone())));
+                    inner.types.push((param.name.as_str(), Bound { ty, env }));
+                }
+                (ParamKind::Nat, Arg::Type(_)) | (ParamKind::Type, Arg::Nat(_)) => {
+                    return Err(unsupported(format!(
+                        "argument kind mismatch for {:?}",
+                        echo(type_name)
+                    )));
+                }
+            }
+        }
+        let items_place = if emit {
+            let constructor = if declaration.constructor == "_" {
+                String::new()
+            } else {
+                declaration.constructor.clone()
+            };
+            self.push(place, constructor)?;
+            place.child("")
+        } else {
+            place.deeper()
+        };
+        self.decode_items(
+            parser,
+            &declaration.items,
+            &mut inner,
+            &declaration.constructor,
+            items_place,
+        )?;
+        Ok(None)
+    }
+
+    /// Decodes the items of one constructor at `place.depth`.
+    fn decode_items(
+        &mut self,
+        parser: &mut CellParser<'_>,
+        items: &'s [Item],
+        env: &mut Env<'s>,
+        constructor: &str,
+        place: Place<'_>,
+    ) -> Outcome<()> {
+        for item in items {
+            self.step()?;
+            match item {
+                Item::Field(field) => {
+                    if let Some(condition) = &field.condition
+                        && !condition_holds(condition, env)?
+                    {
+                        continue;
+                    }
+                    let field_place = Place {
+                        name: &field.name,
+                        ..place
+                    };
+                    let value = self.decode_type(parser, &field.ty, env, field_place)?;
+                    if let Some(value) = value
+                        && field.name != "_"
+                    {
+                        env.nats.push((field.name.as_str(), value));
+                    }
+                }
+                Item::Constraint(constraint) => {
+                    if !constraint_holds(constraint, env)? {
+                        return Err(failure(
+                            TonConnectSignDataCellFailure::ConstraintViolated,
+                            format!("constraint failed in {:?}", echo(constructor)),
+                        ));
+                    }
+                }
+                Item::Inline(items) => {
+                    if place.level >= MAX_DECODE_DEPTH {
+                        return Err(limit("cell nesting is deeper than 32"));
+                    }
+                    let child = next_ref(parser)?;
+                    let mut child_parser = child.parser();
+                    self.decode_items(&mut child_parser, items, env, constructor, place.deeper())?;
+                    ensure_empty(&mut child_parser)?;
+                }
+            }
+        }
+        Ok(())
+    }
+
+    fn decode_sized(
+        &mut self,
+        parser: &mut CellParser<'_>,
+        kind: SizedKind,
+        width: u64,
+        place: Place<'_>,
+    ) -> Outcome<Option<u64>> {
+        check_width(kind, width, false)?;
+        match kind {
+            SizedKind::Uint | SizedKind::NatBits => {
+                let (text, value) = read_uint(parser, width_of(width)?)?;
+                self.push(place, text)?;
+                Ok(value)
+            }
+            SizedKind::Int => {
+                let text = read_int(parser, width_of(width)?)?;
+                self.push(place, text)?;
+                Ok(None)
+            }
+            SizedKind::Bits => {
+                let text = read_bit_string(parser, width_of(width)?)?;
+                self.push(place, text)?;
+                Ok(None)
+            }
+            SizedKind::NatLess | SizedKind::NatLessEqual => {
+                let bound = if kind == SizedKind::NatLess {
+                    width.saturating_sub(1)
+                } else {
+                    width
+                };
+                let value = read_u64(parser, bits_for(bound)?)?;
+                if value > bound {
+                    return Err(failure(
+                        TonConnectSignDataCellFailure::ConstraintViolated,
+                        format!("{value} is above the bound {bound}"),
+                    ));
+                }
+                self.push(place, value.to_string())?;
+                Ok(Some(value))
+            }
+        }
+    }
+
+    fn decode_builtin(
+        &mut self,
+        parser: &mut CellParser<'_>,
+        type_name: &str,
+        args: &'s [Arg],
+        env: &Env<'s>,
+        place: Place<'_>,
+    ) -> Outcome<Option<u64>> {
+        match (type_name, args) {
+            ("Bool", []) => {
+                let value = if read_u64(parser, 1)? == 1 {
+                    "true"
+                } else {
+                    "false"
+                };
+                self.push(place, value.to_owned())?;
+                Ok(None)
+            }
+            ("Maybe", [Arg::Type(inner)]) => {
+                if read_u64(parser, 1)? == 1 {
+                    let _ = self.decode_type(parser, inner, env, place.deeper())?;
+                } else {
+                    self.push(place, "none".to_owned())?;
+                }
+                Ok(None)
+            }
+            ("Either", [Arg::Type(left), Arg::Type(right)]) => {
+                let inner = if read_u64(parser, 1)? == 1 {
+                    right
+                } else {
+                    left
+                };
+                let _ = self.decode_type(parser, inner, env, place.deeper())?;
+                Ok(None)
+            }
+            ("Both", [Arg::Type(first), Arg::Type(second)]) => {
+                self.push(place, "pair".to_owned())?;
+                let _ = self.decode_type(parser, first, env, place.child("first"))?;
+                let _ = self.decode_type(parser, second, env, place.child("second"))?;
+                Ok(None)
+            }
+            ("VarUInteger", [Arg::Nat(bytes)]) => {
+                self.decode_var_integer(parser, env.eval(bytes)?, false, place)
+            }
+            ("VarInteger", [Arg::Nat(bytes)]) => {
+                self.decode_var_integer(parser, env.eval(bytes)?, true, place)
+            }
+            ("Coins" | "Grams", []) => self.decode_var_integer(parser, 16, false, place),
+            ("MsgAddress", []) => self.decode_address(parser, AddressKinds::Any, place),
+            ("MsgAddressInt", []) => self.decode_address(parser, AddressKinds::Internal, place),
+            ("MsgAddressExt", []) => self.decode_address(parser, AddressKinds::External, place),
+            ("Cell" | "Any", []) => {
+                let rest = parser
+                    .read_remaining()
+                    .map_err(|_| truncated("cell ends early"))?;
+                self.check_cell_value(&rest, place.name.len())?;
+                let bytes = BoC::new(rest)
+                    .to_bytes(false)
+                    .map_err(|_| invalid_cell("cell cannot be serialized"))?;
+                let length = bytes
+                    .len()
+                    .checked_mul(2)
+                    .and_then(|length| length.checked_add(place.name.len()))
+                    .ok_or_else(|| limit("result is longer than 32768 bytes"))?;
+                self.ensure_room(length)?;
+                self.push(place, hex(&bytes))?;
+                Ok(None)
+            }
+            _ => Err(unsupported(format!(
+                "unsupported type {:?}",
+                echo(type_name)
+            ))),
+        }
+    }
+
+    /// Bounds a `Cell`/`Any` value before it is serialized.
+    ///
+    /// `BoC` serialization is quadratic in the cell count for some DAG shapes,
+    /// so this linear walk over the distinct cells (by their memoized hashes)
+    /// charges one step per cell and refuses the value once it has more than
+    /// `MAX_CELL_VALUE_CELLS` cells or its estimated hex no longer fits the
+    /// output. The estimate is 2 descriptor bytes, the data bytes and 4 bytes
+    /// per reference for every distinct cell.
+    fn check_cell_value(&mut self, value: &TonCell, name_bytes: usize) -> Outcome<()> {
+        let mut seen = HashSet::new();
+        let mut pending = vec![value];
+        let mut bytes = 0_usize;
+        while let Some(cell) = pending.pop() {
+            let hash = cell
+                .hash()
+                .map_err(|_| invalid_cell("cell cannot be hashed"))?;
+            if !seen.insert(hash) {
+                continue;
+            }
+            self.step()?;
+            if seen.len() > MAX_CELL_VALUE_CELLS {
+                return Err(limit("cell value has more than 256 cells"));
+            }
+            let refs = cell.refs();
+            bytes = refs
+                .len()
+                .checked_mul(4)
+                .and_then(|refs| refs.checked_add(2))
+                .and_then(|size| size.checked_add(cell.data_len_bits().div_ceil(8)))
+                .and_then(|size| size.checked_add(bytes))
+                .ok_or_else(|| limit("result is longer than 32768 bytes"))?;
+            let length = bytes
+                .checked_mul(2)
+                .and_then(|length| length.checked_add(name_bytes))
+                .ok_or_else(|| limit("result is longer than 32768 bytes"))?;
+            self.ensure_room(length)?;
+            pending.extend(refs);
+        }
+        Ok(())
+    }
+
+    /// `VarUInteger n` / `VarInteger n`: a `#< n` byte length, then that many bytes.
+    fn decode_var_integer(
+        &mut self,
+        parser: &mut CellParser<'_>,
+        bytes: u64,
+        signed: bool,
+        place: Place<'_>,
+    ) -> Outcome<Option<u64>> {
+        if !(1..=MAX_VAR_INTEGER_BYTES).contains(&bytes) {
+            return Err(unsupported(format!(
+                "unsupported variable integer size {bytes}"
+            )));
+        }
+        let length = read_u64(parser, bits_for(bytes.saturating_sub(1))?)?;
+        let width = length
+            .checked_mul(8)
+            .ok_or_else(|| unsupported("arithmetic overflow"))?;
+        let width = width_of(width)?;
+        if signed {
+            let text = if width == 0 {
+                "0".to_owned()
+            } else {
+                read_int(parser, width)?
+            };
+            self.push(place, text)?;
+            Ok(None)
+        } else {
+            let (text, value) = read_uint(parser, width)?;
+            self.push(place, text)?;
+            Ok(value)
+        }
+    }
+
+    fn decode_address(
+        &mut self,
+        parser: &mut CellParser<'_>,
+        kinds: AddressKinds,
+        place: Place<'_>,
+    ) -> Outcome<Option<u64>> {
+        let external = matches!(kinds, AddressKinds::Any | AddressKinds::External);
+        let internal = matches!(kinds, AddressKinds::Any | AddressKinds::Internal);
+        let text = match read_u64(parser, 2)? {
+            0b00 if external => "addr_none".to_owned(),
+            0b01 if external => {
+                let length = read_u64(parser, 9)?;
+                let bits = read_bit_string(parser, width_of(length)?)?;
+                format!("addr_extern:{bits}")
+            }
+            0b10 if internal => {
+                if read_u64(parser, 1)? == 1 {
+                    return Err(unsupported("anycast addresses"));
+                }
+                let workchain = read_u64(parser, 8)?;
+                let workchain = u8::try_from(workchain)
+                    .map(|byte| i8::from_be_bytes([byte]))
+                    .map_err(|_| invalid_cell("workchain does not fit 8 bits"))?;
+                require_bits(parser, 256)?;
+                let hash = parser
+                    .read_bits(256)
+                    .map_err(|_| truncated("cell ends early"))?;
+                let hash = <[u8; 32]>::try_from(hash.as_slice())
+                    .map_err(|_| truncated("cell ends early"))?;
+                FriendlyAddress::from_raw(
+                    RawAccountAddress::new(i32::from(workchain), hash),
+                    false,
+                    self.testnet,
+                )
+                .map_or_else(
+                    |_| format!("{workchain}:{}", hex(&hash)),
+                    |address| address.as_str().to_owned(),
+                )
+            }
+            0b11 if internal => return Err(unsupported("addr_var addresses")),
+            _ => {
+                return Err(failure(
+                    TonConnectSignDataCellFailure::TagMismatch,
+                    "address kind does not match its type",
+                ));
+            }
+        };
+        self.push(place, text)?;
+        Ok(None)
+    }
+}
+
+fn condition_holds(condition: &Condition, env: &Env<'_>) -> Outcome<bool> {
+    let flag = env
+        .nat(&condition.flag)
+        .ok_or_else(|| unsupported(format!("{:?} is not a bound number", echo(&condition.flag))))?;
+    Ok(match condition.bit {
+        None => flag != 0,
+        Some(bit) => flag.checked_shr(bit).unwrap_or(0) & 1 == 1,
+    })
+}
+
+fn constraint_holds(constraint: &Constraint, env: &Env<'_>) -> Outcome<bool> {
+    let left = env.eval(&constraint.left)?;
+    let right = env.eval(&constraint.right)?;
+    Ok(match constraint.relation {
+        Relation::Equal => left == right,
+        Relation::Less => left < right,
+        Relation::LessEqual => left <= right,
+        Relation::Greater => left > right,
+        Relation::GreaterEqual => left >= right,
+    })
+}
+
+/// A runtime width as `usize`; a width no cell can hold reads as truncation.
+fn width_of(width: u64) -> Outcome<usize> {
+    usize::try_from(width).map_err(|_| truncated("cell ends early"))
+}
+
+/// Bits needed to write every value up to `value`.
+fn bits_for(value: u64) -> Outcome<usize> {
+    let bits = u64::BITS.saturating_sub(value.leading_zeros());
+    usize::try_from(bits).map_err(|_| unsupported("unsupported width"))
+}
+
+fn bits_left(parser: &mut CellParser<'_>) -> Outcome<usize> {
+    parser
+        .data_bits_left()
+        .map_err(|_| invalid_cell("cell cannot be read"))
+}
+
+/// Fails with `TruncatedCell` unless `width` bits remain; every read calls it first.
+fn require_bits(parser: &mut CellParser<'_>, width: usize) -> Outcome<()> {
+    let left = bits_left(parser)?;
+    if width > left {
+        return Err(truncated(format!(
+            "cell ends early: {width} bits needed, {left} left"
+        )));
+    }
+    Ok(())
+}
+
+/// Reads at most 64 bits as an unsigned number.
+fn read_u64(parser: &mut CellParser<'_>, width: usize) -> Outcome<u64> {
+    if width > 64 {
+        return Err(unsupported("unsupported width"));
+    }
+    require_bits(parser, width)?;
+    parser
+        .read_num::<u64>(width)
+        .map_err(|_| truncated("cell ends early"))
+}
+
+/// Reads an unsigned number of up to 256 bits as decimal, with its value when it fits `u64`.
+fn read_uint(parser: &mut CellParser<'_>, width: usize) -> Outcome<(String, Option<u64>)> {
+    if width <= 64 {
+        let value = read_u64(parser, width)?;
+        return Ok((value.to_string(), Some(value)));
+    }
+    require_bits(parser, width)?;
+    let value = parser
+        .read_num::<BigUint>(width)
+        .map_err(|_| truncated("cell ends early"))?;
+    Ok((value.to_string(), u64::try_from(&value).ok()))
+}
+
+/// Reads a two's-complement number of 1 to 257 bits as decimal.
+fn read_int(parser: &mut CellParser<'_>, width: usize) -> Outcome<String> {
+    require_bits(parser, width)?;
+    let value = parser
+        .read_num::<BigInt>(width)
+        .map_err(|_| truncated("cell ends early"))?;
+    Ok(value.to_string())
+}
+
+fn read_bit_string(parser: &mut CellParser<'_>, width: usize) -> Outcome<String> {
+    require_bits(parser, width)?;
+    let bytes = parser
+        .read_bits(width)
+        .map_err(|_| truncated("cell ends early"))?;
+    Ok(hex_bits(&bytes, width))
+}
+
+/// The next reference, refused when missing or exotic.
+fn next_ref(parser: &mut CellParser<'_>) -> Outcome<TonCell> {
+    if parser.refs_left() == 0 {
+        return Err(truncated("cell ends before a reference"));
+    }
+    let child = parser
+        .read_next_ref()
+        .map_err(|_| truncated("cell ends before a reference"))?
+        .clone();
+    if child.cell_type().is_exotic() {
+        return Err(invalid_cell("exotic cells are not decodable"));
+    }
+    Ok(child)
+}
+
+fn ensure_empty(parser: &mut CellParser<'_>) -> Outcome<()> {
+    let bits = bits_left(parser)?;
+    let refs = parser.refs_left();
+    if bits == 0 && refs == 0 {
+        return Ok(());
+    }
+    Err(failure(
+        TonConnectSignDataCellFailure::TrailingData,
+        format!("{bits} bits and {refs} refs left"),
+    ))
+}
+
+fn hex_digit(nibble: u8) -> char {
+    char::from_digit(u32::from(nibble), 16).unwrap_or('0')
+}
+
+/// Lowercase hex of whole bytes.
+fn hex(bytes: &[u8]) -> String {
+    let mut text = String::with_capacity(bytes.len().saturating_mul(2));
+    for byte in bytes {
+        text.push(hex_digit(byte.wrapping_shr(4)));
+        text.push(hex_digit(byte & 0x0f));
+    }
+    text
+}
+
+/// Hex of the first `len` bits of `bytes` (zero-padded as `read_bits` returns them).
+///
+/// A length that is not a multiple of 4 uses the Fift form: the last nibble
+/// carries a completion `1` bit after the data bits, followed by `_`.
+fn hex_bits(bytes: &[u8], len: usize) -> String {
+    let mut nibbles = bytes
+        .iter()
+        .flat_map(|byte| [byte.wrapping_shr(4), byte & 0x0f])
+        .collect::<Vec<_>>();
+    nibbles.truncate(len.div_ceil(4));
+    let completion = match len & 3 {
+        1 => 0b0100,
+        2 => 0b0010,
+        3 => 0b0001,
+        _ => 0,
+    };
+    if completion != 0
+        && let Some(last) = nibbles.last_mut()
+    {
+        *last |= completion;
+    }
+    let mut text = nibbles.into_iter().map(hex_digit).collect::<String>();
+    if completion != 0 {
+        text.push('_');
+    }
+    text
+}
+
+#[cfg(test)]
+mod tests {
+    use std::panic::catch_unwind;
+    use std::str::FromStr as _;
+    use std::time::{Duration, Instant};
+
+    use base64::{Engine as _, engine::general_purpose::STANDARD};
+    use ton::ton_core::cell::CellBuilder;
+    use ton::ton_core::errors::TonCoreError;
+    use ton::ton_core::types::TonAddress;
+
+    use super::*;
+    use TonConnectSignDataCellFailure as F;
+
+    const DEMO_SCHEMA: &str = "message#_ len:uint7 {len <= 127} text:(bits len * 8) = Message;";
+    /// The demo dApp's cell exactly as `@ton/core` `toBoc()` sends it (with CRC-32C).
+    const DEMO_MESSAGE_CELL: &str = "te6cckEBAQEAFwAAKSioyuboQNrK5ubCzspA0txAxsrY2Whv0fw=";
+    const DEMO_TEXT: &str = "Test message in cell";
+
+    const WALLET_SCHEMA: &str = "wallet_body#_ signature:bits512 subwallet_id:uint32 valid_until:uint32 seqno:uint32 = WalletBody;";
+    const SIGNATURE: &str = "2bfcd9ad9768087dbbb5e70623edb351842a0dd039ef3a2521e62f081c8dc66fd5a0c1ad403a5660a102230652ce7bf07f08095d26786dc3152aa0849008910c";
+
+    const ORDER_SCHEMA: &str = "// comment
+memo#_ text:(bits 40) urgent:Bool = Memo;
+point$_ x:int8 y:(## 4) = Point;
+order#1234abcd query_id:uint64 amount:Coins to:MsgAddress at:Point memo:^Memo extra:(Maybe ^Cell) = Order;";
+
+    const NON_BOUNCEABLE: &str = "UQCKWpx7cNMpvmcN5ObM5lLUZHZRFKqYA4xmw9jOry0ZsAKJ";
+    const DESTINATION_RAW: &str =
+        "0:8a5a9c7b70d329be670de4e6cce652d464765114aa98038c66c3d8ceaf2d19b0";
+
+    const PROMPT: Duration = Duration::from_secs(2);
+
+    fn cell(build: impl FnOnce(&mut CellBuilder) -> Result<(), TonCoreError>) -> TonCell {
+        let mut builder = TonCell::builder();
+        build(&mut builder).expect("cell builds");
+        builder.build().expect("cell builds")
+    }
+
+    fn boc(cell: TonCell) -> String {
+        STANDARD.encode(BoC::new(cell).to_bytes(false).expect("BoC serializes"))
+    }
+
+    fn hex_of(bytes: &[u8]) -> String {
+        bytes.iter().map(|byte| format!("{byte:02x}")).collect()
+    }
+
+    fn decoded(schema: &str, cell: &str, testnet: bool) -> Vec<(u32, String, String)> {
+        match decode_sign_data_cell(schema, cell, testnet) {
+            TonConnectSignDataCellDecoding::Decoded { fields } => fields
+                .into_iter()
+                .map(|field| (field.depth, field.name, field.value))
+                .collect(),
+            TonConnectSignDataCellDecoding::NotDecodable { failure, detail } => {
+                panic!("not decodable: {failure:?} {detail}")
+            }
+        }
+    }
+
+    fn entries(expected: &[(u32, &str, &str)]) -> Vec<(u32, String, String)> {
+        expected
+            .iter()
+            .map(|(depth, name, value)| (*depth, (*name).to_owned(), (*value).to_owned()))
+            .collect()
+    }
+
+    /// The failure of a not-decodable cell; a field list fails the test.
+    fn failure_of(schema: &str, cell: &str) -> (F, String) {
+        match decode_sign_data_cell(schema, cell, false) {
+            TonConnectSignDataCellDecoding::NotDecodable { failure, detail } => (failure, detail),
+            TonConnectSignDataCellDecoding::Decoded { fields } => {
+                panic!("unexpectedly decoded: {fields:?}")
+            }
+        }
+    }
+
+    fn failure(schema: &str, cell: &str) -> F {
+        failure_of(schema, cell).0
+    }
+
+    /// Asserts a failure category and that the call returned within `PROMPT`.
+    fn prompt_failure(schema: &str, cell: &str) -> (F, String) {
+        let start = Instant::now();
+        let result = failure_of(schema, cell);
+        assert!(start.elapsed() < PROMPT, "took {:?}", start.elapsed());
+        result
+    }
+
+    fn demo_cell(len: u8, text: &[u8]) -> TonCell {
+        cell(|builder| {
+            builder.write_num(&len, 7)?;
+            builder.write_bits(text, text.len() * 8)
+        })
+    }
+
+    fn demo_boc() -> String {
+        boc(demo_cell(20, DEMO_TEXT.as_bytes()))
+    }
+
+    fn signature_bytes() -> Vec<u8> {
+        SIGNATURE
+            .as_bytes()
+            .chunks(2)
+            .map(|pair| u8::from_str_radix(std::str::from_utf8(pair).unwrap(), 16).unwrap())
+            .collect()
+    }
+
+    fn wallet_cell(with_seqno: bool) -> TonCell {
+        let signature = signature_bytes();
+        cell(|builder| {
+            builder.write_bits(&signature, 512)?;
+            builder.write_num(&698_983_191_u32, 32)?;
+            builder.write_num(&1_740_048_389_u32, 32)?;
+            if with_seqno {
+                builder.write_num(&123_u32, 32)?;
+            }
+            Ok(())
+        })
+    }
+
+    fn destination_hash() -> [u8; 32] {
+        *TonAddress::from_str(DESTINATION_RAW)
+            .unwrap()
+            .hash
+            .as_slice_sized()
+    }
+
+    fn write_std_address(builder: &mut CellBuilder, anycast: bool) -> Result<(), TonCoreError> {
+        builder.write_num(&0b10_u8, 2)?;
+        builder.write_bit(anycast)?;
+        builder.write_num(&0_u8, 8)?;
+        builder.write_bits(destination_hash(), 256)
+    }
+
+    fn memo_cell(extra_bit: bool) -> TonCell {
+        cell(|builder| {
+            builder.write_bits(b"hello", 40)?;
+            builder.write_bit(true)?;
+            if extra_bit {
+                builder.write_bit(false)?;
+            }
+            Ok(())
+        })
+    }
+
+    /// The order cell of `ORDER_SCHEMA`; `memo` is its reference (if any), `extra` the `Maybe ^Cell`.
+    fn order_cell(memo: Option<TonCell>, extra: Option<TonCell>) -> TonCell {
+        cell(|builder| {
+            builder.write_num(&0x1234_abcd_u32, 32)?;
+            builder.write_num(&7_u64, 64)?;
+            builder.write_num(&4_u8, 4)?;
+            builder.write_num(&1_000_000_000_u32, 32)?;
+            write_std_address(builder, false)?;
+            builder.write_num(&(-5_i8), 8)?;
+            builder.write_num(&9_u8, 4)?;
+            if let Some(memo) = memo {
+                builder.write_ref(memo)?;
+            }
+            builder.write_bit(extra.is_some())?;
+            if let Some(extra) = extra {
+                builder.write_ref(extra)?;
+            }
+            Ok(())
+        })
+    }
+
+    fn expected_order(address: &str, extra: &str) -> Vec<(u32, String, String)> {
+        entries(&[
+            (0, "query_id", "7"),
+            (0, "amount", "1000000000"),
+            (0, "to", address),
+            (0, "at", "point"),
+            (1, "x", "-5"),
+            (1, "y", "9"),
+            (0, "memo", "memo"),
+            (1, "text", "68656c6c6f"),
+            (1, "urgent", "true"),
+            (0, "extra", extra),
+        ])
+    }
+
+    #[test]
+    fn demo_message_decodes_into_len_and_text() {
+        let text_hex = hex_of(DEMO_TEXT.as_bytes());
+        assert_eq!(text_hex, "54657374206d65737361676520696e2063656c6c");
+        let expected = entries(&[(0, "len", "20"), (0, "text", &text_hex)]);
+        let built = demo_cell(20, DEMO_TEXT.as_bytes());
+        assert_eq!(
+            STANDARD.encode(BoC::new(built.clone()).to_bytes(true).unwrap()),
+            DEMO_MESSAGE_CELL
+        );
+        assert_eq!(decoded(DEMO_SCHEMA, DEMO_MESSAGE_CELL, false), expected);
+        assert_eq!(decoded(DEMO_SCHEMA, &boc(built), true), expected);
+    }
+
+    #[test]
+    fn wallet_style_body_decodes_into_its_four_fields() {
+        assert_eq!(hex_of(&signature_bytes()), SIGNATURE);
+        assert_eq!(
+            decoded(WALLET_SCHEMA, &boc(wallet_cell(true)), false),
+            entries(&[
+                (0, "signature", SIGNATURE),
+                (0, "subwallet_id", "698983191"),
+                (0, "valid_until", "1740048389"),
+                (0, "seqno", "123"),
+            ])
+        );
+        // Control: the same cell under a mismatching schema is not decodable.
+        assert_eq!(
+            failure(DEMO_SCHEMA, &boc(wallet_cell(true))),
+            F::TrailingData
+        );
+    }
+
+    #[test]
+    fn referenced_cell_and_declared_sub_type_decode_as_nested_fields() {
+        let address = TonAddress::from_str(DESTINATION_RAW).unwrap();
+        let mainnet = address.to_base64(true, false, true);
+        let testnet = address.to_base64(false, false, true);
+        assert_eq!(mainnet, NON_BOUNCEABLE);
+        assert!(testnet.starts_with("0Q"), "{testnet}");
+        assert_ne!(mainnet, testnet);
+
+        let order = boc(order_cell(Some(memo_cell(false)), None));
+        assert_eq!(
+            decoded(ORDER_SCHEMA, &order, false),
+            expected_order(NON_BOUNCEABLE, "none")
+        );
+        assert_eq!(
+            decoded(ORDER_SCHEMA, &order, true),
+            expected_order(&testnet, "none")
+        );
+
+        let extra = cell(|builder| builder.write_num(&0xff_u8, 8));
+        let extra_hex = hex_of(&BoC::new(extra.clone()).to_bytes(false).unwrap());
+        let order = boc(order_cell(Some(memo_cell(false)), Some(extra)));
+        assert_eq!(
+            decoded(ORDER_SCHEMA, &order, false),
+            expected_order(NON_BOUNCEABLE, &extra_hex)
+        );
+        // Control: the same cell under a mismatching schema is not decodable.
+        assert_eq!(failure(WALLET_SCHEMA, &order), F::TruncatedCell);
+    }
+
+    #[test]
+    fn parameterized_and_standard_types() {
+        let schema = "
+            opt_none$0 {X:Type} = Opt X;
+            opt_some$1 {X:Type} value:X = Opt X;
+            blob$_ {n:#} data:(bits n) = Blob n;
+            yes$1 = YN; no$0 = YN;
+            t#_ a:(Opt uint8) b:(Opt uint8) c:(Blob 16) e:(Either uint8 ^Cell)
+                f:(Either uint8 ^Cell) flag:(## 1) x:flag?uint8 flag2:(## 1) y:flag2?uint8
+                mode:(## 8) z:(mode . 2)?uint8 w:(mode . 1)?uint8
+                big:(VarUInteger 32) small:(VarInteger 2) none:MsgAddress ext:MsgAddressExt
+                odd:(bits 5) pair:(Both uint8 Bool) yn:YN nyn:YN lt:(#< 5) le:(#<= 5) = T;";
+        let referenced = cell(|builder| builder.write_num(&0xab_u8, 8));
+        let referenced_hex = hex_of(&BoC::new(referenced.clone()).to_bytes(false).unwrap());
+        let big = BigUint::from(u64::MAX) + 1_u32;
+        let built = cell(|builder| {
+            builder.write_bit(false)?; // a: opt_none
+            builder.write_bit(true)?; // b: opt_some
+            builder.write_num(&42_u8, 8)?;
+            builder.write_num(&0xbeef_u16, 16)?; // c
+            builder.write_bit(false)?; // e: left
+            builder.write_num(&7_u8, 8)?;
+            builder.write_bit(true)?; // f: right
+            builder.write_ref(referenced)?;
+            builder.write_num(&0_u8, 1)?; // flag
+            builder.write_num(&1_u8, 1)?; // flag2
+            builder.write_num(&9_u8, 8)?; // y
+            builder.write_num(&4_u8, 8)?; // mode: bit 2 set, bit 1 clear
+            builder.write_num(&10_u8, 8)?; // z
+            builder.write_num(&9_u8, 5)?; // big: 9 bytes
+            builder.write_num(&big, 72)?;
+            builder.write_num(&1_u8, 1)?; // small: 1 byte
+            builder.write_num(&(-3_i8), 8)?;
+            builder.write_num(&0_u8, 2)?; // none: addr_none
+            builder.write_num(&1_u8, 2)?; // ext: addr_extern
+            builder.write_num(&12_u16, 9)?;
+            builder.write_num(&0xabc_u16, 12)?;
+            builder.write_num(&0b10101_u8, 5)?; // odd
+            builder.write_num(&1_u8, 8)?; // pair.first
+            builder.write_bit(true)?; // pair.second
+            builder.write_bit(true)?; // yn
+            builder.write_bit(false)?; // nyn
+            builder.write_num(&4_u8, 3)?; // lt: #< 5 is 3 bits
+            builder.write_num(&5_u8, 3)?; // le: #<= 5 is 3 bits
+            Ok(())
+        });
+        assert_eq!(
+            decoded(schema, &boc(built), false),
+            entries(&[
+                (0, "a", "opt_none"),
+                (0, "b", "opt_some"),
+                (1, "value", "42"),
+                (0, "c", "blob"),
+                (1, "data", "beef"),
+                (0, "e", "7"),
+                (0, "f", &referenced_hex),
+                (0, "flag", "0"),
+                (0, "flag2", "1"),
+                (0, "y", "9"),
+                (0, "mode", "4"),
+                (0, "z", "10"),
+                (0, "big", "18446744073709551616"),
+                (0, "small", "-3"),
+                (0, "none", "addr_none"),
+                (0, "ext", "addr_extern:abc"),
+                (0, "odd", "ac_"),
+                (0, "pair", "pair"),
+                (1, "first", "1"),
+                (1, "second", "true"),
+                (0, "yn", "yes"),
+                (0, "nyn", "no"),
+                (0, "lt", "4"),
+                (0, "le", "5"),
+            ])
+        );
+    }
+
+    #[test]
+    fn bit_strings_use_hex_or_the_fift_form() {
+        assert_eq!(hex_bits(&[], 0), "");
+        assert_eq!(hex_bits(&[0b1010_1000], 5), "ac_");
+        assert_eq!(hex_bits(&[0b1000_0000], 1), "c_");
+        assert_eq!(hex_bits(&[0b1100_0000], 2), "e_");
+        assert_eq!(hex_bits(&[0b1110_0000], 3), "f_");
+        assert_eq!(hex_bits(&[0xab, 0xc0], 12), "abc");
+        assert_eq!(hex_bits(&[0xab], 8), "ab");
+    }
+
+    #[test]
+    fn unsupported_constructs_are_not_decodable() {
+        let one_byte = boc(cell(|builder| builder.write_num(&1_u8, 8)));
+        for schema in [
+            "message len:uint7 = Message;",
+            "message# len:uint7 = Message;",
+            "d#_ m:(HashmapE 32 uint8) = D;",
+            "t#_ x:(3 * uint8) = T;",
+            "t#_ {n:#} x:(n * uint8) = T;",
+            "a#_ {n:#} x:(## n) = A ~n;",
+            "a#_ x:(## 8) {~x = 1} = A;",
+            "!a#_ x:uint8 = A;",
+            "a#_ x:[ y:uint8 ] = A;",
+            "a#_ {n:#} x:(## n) = A n;",
+            "a#_ x:uint300 = A;",
+            "a#_ x:int258 = A;",
+            "a#_ x:bits1024 = A;",
+            "a#_ x:(## 65) = A;",
+            "a#_ x:int0 = A;",
+            "a#_ x:y?uint8 = A;",
+            "a$_ = A; b$_ = A; c#_ x:A y:uint8 = C;",
+        ] {
+            assert_eq!(failure(schema, &one_byte), F::UnsupportedSchema, "{schema}");
+        }
+        let address = |anycast: bool, var: bool| {
+            boc(cell(|builder| {
+                if var {
+                    builder.write_num(&0b11_u8, 2)?;
+                    builder.write_bit(false)?;
+                    builder.write_num(&8_u16, 9)?;
+                    builder.write_num(&0_u32, 32)?;
+                    builder.write_num(&0_u8, 8)
+                } else {
+                    write_std_address(builder, anycast)
+                }
+            }))
+        };
+        let schema = "a#_ to:MsgAddress = A;";
+        assert_eq!(failure(schema, &address(true, false)), F::UnsupportedSchema);
+        assert_eq!(failure(schema, &address(false, true)), F::UnsupportedSchema);
+        assert_eq!(
+            decoded(schema, &address(false, false), false),
+            entries(&[(0, "to", NON_BOUNCEABLE)])
+        );
+    }
+
+    #[test]
+    fn tag_mismatches_are_not_decodable() {
+        let two_bytes = boc(cell(|builder| builder.write_num(&0x0205_u16, 16)));
+        assert_eq!(failure("a#01 x:uint8 = A;", &two_bytes), F::TagMismatch);
+        assert_eq!(
+            decoded("a#02 x:uint8 = A;", &two_bytes, false),
+            entries(&[(0, "x", "5")])
+        );
+        let two_bits = boc(cell(|builder| builder.write_num(&0b01_u8, 2)));
+        let schema = "a$11 = T; b$10 = T; w#_ t:T = W;";
+        assert_eq!(failure(schema, &two_bits), F::TagMismatch);
+        let matching = boc(cell(|builder| builder.write_num(&0b10_u8, 2)));
+        assert_eq!(decoded(schema, &matching, false), entries(&[(0, "t", "b")]));
+        // A completion tag: `#a_` (`1010`) is the two bits `10`.
+        let completion = boc(cell(|builder| builder.write_num(&0b10_u8, 2)));
+        assert_eq!(decoded("x#a_ = X;", &completion, false), entries(&[]));
+        // An internal address type refuses `addr_none`.
+        let none = boc(cell(|builder| builder.write_num(&0_u8, 2)));
+        assert_eq!(failure("a#_ to:MsgAddressInt = A;", &none), F::TagMismatch);
+    }
+
+    #[test]
+    fn the_root_is_the_last_declaration() {
+        let schema = "approve#01 amount:uint8 = Op; revoke#02 amount:uint8 = Op;";
+        let approve = boc(cell(|builder| builder.write_num(&0x0105_u16, 16)));
+        let revoke = boc(cell(|builder| builder.write_num(&0x0205_u16, 16)));
+        assert_eq!(
+            decoded(schema, &revoke, false),
+            entries(&[(0, "amount", "5")])
+        );
+        assert_eq!(failure(schema, &approve), F::TagMismatch);
+        let short = boc(cell(|builder| builder.write_num(&0b0010_u8, 4)));
+        assert_eq!(failure(schema, &short), F::TruncatedCell);
+
+        // Control: every constructor of the type still serves a nested use.
+        let nested = format!("{schema} w#_ op:Op = W;");
+        assert_eq!(
+            decoded(&nested, &approve, false),
+            entries(&[(0, "op", "approve"), (1, "amount", "5")])
+        );
+        assert_eq!(
+            decoded(&nested, &revoke, false),
+            entries(&[(0, "op", "revoke"), (1, "amount", "5")])
+        );
+    }
+
+    #[test]
+    fn violated_constraints_are_not_decodable() {
+        let demo = demo_boc();
+        let strict = "message#_ len:uint7 {len <= 16} text:(bits len * 8) = Message;";
+        assert_eq!(failure(strict, &demo), F::ConstraintViolated);
+        let larger = "message#_ len:uint7 {len >= 21} text:(bits len * 8) = Message;";
+        assert_eq!(failure(larger, &demo), F::ConstraintViolated);
+        assert_eq!(decoded(DEMO_SCHEMA, &demo, false).len(), 2);
+        let bounded = boc(cell(|builder| builder.write_num(&5_u8, 3)));
+        assert_eq!(
+            failure("a#_ x:(#< 5) = A;", &bounded),
+            F::ConstraintViolated
+        );
+    }
+
+    #[test]
+    fn trailing_data_is_not_decodable() {
+        let extra_bit = boc(cell(|builder| {
+            builder.write_num(&20_u8, 7)?;
+            builder.write_bits(DEMO_TEXT.as_bytes(), 160)?;
+            builder.write_bit(false)
+        }));
+        assert_eq!(failure(DEMO_SCHEMA, &extra_bit), F::TrailingData);
+        let extra_ref = boc(cell(|builder| {
+            builder.write_num(&20_u8, 7)?;
+            builder.write_bits(DEMO_TEXT.as_bytes(), 160)?;
+            builder.write_ref(TonCell::empty().clone())
+        }));
+        assert_eq!(failure(DEMO_SCHEMA, &extra_ref), F::TrailingData);
+        let child_extra = boc(order_cell(Some(memo_cell(true)), None));
+        assert_eq!(failure(ORDER_SCHEMA, &child_extra), F::TrailingData);
+    }
+
+    #[test]
+    fn truncated_cells_are_not_decodable() {
+        let short_text = boc(demo_cell(20, &DEMO_TEXT.as_bytes()[..19]));
+        assert_eq!(failure(DEMO_SCHEMA, &short_text), F::TruncatedCell);
+        assert_eq!(
+            failure(WALLET_SCHEMA, &boc(wallet_cell(false))),
+            F::TruncatedCell
+        );
+        let no_memo = boc(order_cell(None, None));
+        assert_eq!(failure(ORDER_SCHEMA, &no_memo), F::TruncatedCell);
+    }
+
+    #[test]
+    fn schemas_that_fail_to_parse_are_not_decodable() {
+        let cell = demo_boc();
+        for schema in [
+            "",
+            "   // only a comment",
+            "message#_ len:uint7 {len <= 127 text:(bits len * 8) = Message;",
+            "message#_ len:uint7",
+            "/* unterminated",
+            "a#_ x:uint8 = A; @",
+            "a#_ x:(uint8 = A;",
+            "a#_ x:uint8 = ;",
+            "a$ x:uint8 = A;",
+        ] {
+            assert_eq!(failure(schema, &cell), F::InvalidSchema, "{schema:?}");
+        }
+    }
+
+    #[test]
+    fn invalid_cells_are_not_decodable() {
+        assert_eq!(failure(DEMO_SCHEMA, "not a boc"), F::InvalidCell);
+        let root = demo_cell(20, DEMO_TEXT.as_bytes());
+        let two_roots = STANDARD.encode(
+            BoC::from_roots([root, TonCell::empty().clone()])
+                .to_bytes(false)
+                .unwrap(),
+        );
+        assert_eq!(failure(DEMO_SCHEMA, &two_roots), F::InvalidCell);
+    }
+
+    #[test]
+    fn no_progress_recursion_is_bounded() {
+        let one_byte = boc(cell(|builder| builder.write_num(&1_u8, 8)));
+        let (kind, _) = prompt_failure("a$_ x:A = A;", &one_byte);
+        assert_eq!(kind, F::LimitExceeded);
+    }
+
+    /// A list of `length` cells, each `v:uint8` then `Maybe ^R`.
+    fn chain(length: usize) -> String {
+        let mut next: Option<TonCell> = None;
+        for index in 0..length {
+            let previous = next.take();
+            next = Some(cell(|builder| {
+                builder.write_num(&u8::try_from(index % 256).unwrap(), 8)?;
+                builder.write_bit(previous.is_some())?;
+                if let Some(previous) = previous {
+                    builder.write_ref(previous)?;
+                }
+                Ok(())
+            }));
+        }
+        boc(next.unwrap())
+    }
+
+    #[test]
+    fn deep_reference_chains_are_bounded() {
+        let schema = "r$_ v:uint8 next:(Maybe ^R) = R;";
+        let (kind, detail) = prompt_failure(schema, &chain(64));
+        assert_eq!(kind, F::LimitExceeded);
+        assert!(detail.contains("nesting"), "{detail}");
+
+        let fields = decoded(schema, &chain(5), false);
+        let depths = fields
+            .iter()
+            .filter(|(_, name, _)| name == "next")
+            .map(|(depth, _, _)| *depth)
+            .collect::<Vec<_>>();
+        assert_eq!(depths, [0, 1, 2, 3, 4]);
+
+        // Each list level costs three decode levels (`Maybe`, `^`, `R`), so
+        // 11 cells are the longest chain within `MAX_DECODE_DEPTH`.
+        assert!(matches!(
+            decode_sign_data_cell(schema, &chain(11), false),
+            TonConnectSignDataCellDecoding::Decoded { .. }
+        ));
+        assert_eq!(failure(schema, &chain(12)), F::LimitExceeded);
+    }
+
+    #[test]
+    fn shared_reference_fan_out_is_bounded() {
+        let schema = "n$_ a:(Maybe ^N) b:(Maybe ^N) c:(Maybe ^N) d:(Maybe ^N) = N;";
+        let mut level = cell(|builder| builder.write_num(&0_u8, 4));
+        for _ in 0..6 {
+            let child = level.clone();
+            level = cell(|builder| {
+                builder.write_num(&0b1111_u8, 4)?;
+                for _ in 0..4 {
+                    builder.write_ref(child.clone())?;
+                }
+                Ok(())
+            });
+        }
+        let (kind, _) = prompt_failure(schema, &boc(level));
+        assert_eq!(kind, F::LimitExceeded);
+    }
+
+    #[test]
+    fn huge_sizes_are_bounded() {
+        let all_ones = boc(cell(|builder| builder.write_num(&u64::MAX, 64)));
+        let (kind, _) = prompt_failure("x#_ len:(## 64) data:(bits len) = X;", &all_ones);
+        assert_eq!(kind, F::TruncatedCell);
+        let (kind, _) = prompt_failure("x#_ data:(bits 99999999999999999999) = X;", &all_ones);
+        assert_eq!(kind, F::LimitExceeded);
+        let overflow = boc(cell(|builder| {
+            builder.write_num(&(1_u64 << 40), 64)?;
+            builder.write_num(&(1_u64 << 40), 64)
+        }));
+        let (kind, _) = prompt_failure("x#_ a:(## 64) b:(## 64) data:(bits a * b) = X;", &overflow);
+        assert_eq!(kind, F::UnsupportedSchema);
+        let huge_uint = boc(cell(|builder| {
+            builder.write_num(&255_u8, 8)?;
+            builder.write_num(&0_u8, 8)
+        }));
+        let (kind, _) = prompt_failure("x#_ n:uint8 v:(uint n * 2) = X;", &huge_uint);
+        assert_eq!(kind, F::UnsupportedSchema);
+    }
+
+    /// A one-root `BoC` of `cells` (data bytes, reference indices) listed parents first.
+    fn raw_boc(cells: &[(Vec<u8>, Vec<usize>)]) -> String {
+        let mut body = Vec::new();
+        for (data, refs) in cells {
+            body.push(u8::try_from(refs.len()).unwrap());
+            body.push(u8::try_from(data.len() * 2).unwrap());
+            body.extend_from_slice(data);
+            for index in refs {
+                body.extend_from_slice(&u16::try_from(*index).unwrap().to_be_bytes());
+            }
+        }
+        let mut bytes = vec![0xb5, 0xee, 0x9c, 0x72, 0x02, 0x04];
+        bytes.extend_from_slice(&u16::try_from(cells.len()).unwrap().to_be_bytes());
+        bytes.extend_from_slice(&[0, 1, 0, 0]);
+        bytes.extend_from_slice(&u32::try_from(body.len()).unwrap().to_be_bytes());
+        bytes.extend_from_slice(&[0, 0]);
+        bytes.extend_from_slice(&body);
+        STANDARD.encode(bytes)
+    }
+
+    /// A DAG of `2 * length + 1` cells whose breadth-first order is not
+    /// topological: root -> [d1, c1], c_i -> [c_i+1, d_i], d_i -> [d_i+1].
+    /// `wrapped` puts it behind one reference of an empty root cell.
+    fn non_topological_dag(length: usize, wrapped: bool) -> String {
+        let offset = usize::from(wrapped);
+        let root = offset;
+        let c = |index: usize| offset + index;
+        let d = |index: usize| offset + length + index;
+        let data = |index: usize| u16::try_from(index).unwrap().to_be_bytes().to_vec();
+        let mut cells = Vec::new();
+        if wrapped {
+            cells.push((Vec::new(), vec![root]));
+        }
+        cells.push((data(0), vec![d(1), c(1)]));
+        for index in 1..=length {
+            let refs = if index < length {
+                vec![c(index + 1), d(index)]
+            } else {
+                vec![d(index)]
+            };
+            cells.push((data(index), refs));
+        }
+        for index in 1..=length {
+            let refs = if index < length {
+                vec![d(index + 1)]
+            } else {
+                Vec::new()
+            };
+            cells.push((data(length + index), refs));
+        }
+        raw_boc(&cells)
+    }
+
+    #[test]
+    fn large_cell_values_are_bounded() {
+        // The DAG is 1 002 levels deep; drop it on a thread with room for that.
+        std::thread::Builder::new()
+            .stack_size(256 << 20)
+            .spawn(|| {
+                for (schema, wrapped) in [("a#_ c:^Cell = A;", true), ("a#_ c:Any = A;", false)] {
+                    let dag = non_topological_dag(1_000, wrapped);
+                    let (kind, detail) = prompt_failure(schema, &dag);
+                    assert_eq!(kind, F::LimitExceeded, "{schema}: {detail}");
+                    assert!(detail.contains("256 cells"), "{schema}: {detail}");
+                    let too_deep = non_topological_dag(4_000, wrapped);
+                    assert_eq!(
+                        failure_of(schema, &too_deep),
+                        (F::InvalidCell, "cell is not a one-root BoC".to_owned())
+                    );
+                }
+                // Control: a small DAG of the same shape is shown in full.
+                let small = non_topological_dag(3, true);
+                let fields = decoded("a#_ c:^Cell = A;", &small, false);
+                assert_eq!(fields.len(), 1);
+                assert!(fields[0].2.starts_with("b5ee9c72"), "{fields:?}");
+            })
+            .unwrap()
+            .join()
+            .unwrap();
+    }
+
+    #[test]
+    fn long_schemas_are_bounded() {
+        let cell = demo_boc();
+        let long = format!("{DEMO_SCHEMA}{}", " ".repeat(MAX_SCHEMA_BYTES));
+        let (kind, detail) = prompt_failure(&long, &cell);
+        assert_eq!(kind, F::LimitExceeded);
+        assert!(detail.contains("bytes"), "{detail}");
+
+        let tokens = format!("a#_ {}= A;", "_:# ".repeat(1_700));
+        let (kind, detail) = prompt_failure(&tokens, &cell);
+        assert_eq!(kind, F::LimitExceeded);
+        assert!(detail.contains("tokens"), "{detail}");
+
+        let declarations = "a$_ = A;".repeat(129);
+        let (kind, detail) = prompt_failure(&declarations, &cell);
+        assert_eq!(kind, F::LimitExceeded);
+        assert!(detail.contains("declarations"), "{detail}");
+
+        let nested = format!("a#_ x:{}uint8{} = A;", "(".repeat(40), ")".repeat(40));
+        let (kind, detail) = prompt_failure(&nested, &cell);
+        assert_eq!(kind, F::LimitExceeded);
+        assert!(detail.contains("nesting"), "{detail}");
+
+        let very_nested = format!("a#_ x:{}uint8 = A;", "(".repeat(10_000));
+        let (kind, detail) = prompt_failure(&very_nested, &cell);
+        assert_eq!(kind, F::LimitExceeded);
+        assert!(detail.contains("tokens"), "{detail}");
+
+        let fields = format!("a#_ {}= A;", "_:bits0 ".repeat(65));
+        let (kind, detail) = prompt_failure(&fields, &cell);
+        assert_eq!(kind, F::LimitExceeded);
+        assert!(detail.contains("fields"), "{detail}");
+
+        let chain = format!("a#_ x:(bits {}1) = A;", "1 + ".repeat(40));
+        let (kind, detail) = prompt_failure(&chain, &cell);
+        assert_eq!(kind, F::LimitExceeded);
+        assert!(detail.contains("nesting"), "{detail}");
+    }
+
+    #[test]
+    fn output_is_bounded() {
+        let names = (0..64)
+            .map(|index| format!("f{index}:bits0 "))
+            .collect::<String>();
+        let schema =
+            format!("leaf$_ {names}= Leaf; root$_ a:^Leaf b:^Leaf c:^Leaf d:^Leaf = Root;");
+        let root = cell(|builder| {
+            for _ in 0..4 {
+                builder.write_ref(TonCell::empty().clone())?;
+            }
+            Ok(())
+        });
+        let (kind, detail) = prompt_failure(&schema, &boc(root));
+        assert_eq!(kind, F::LimitExceeded);
+        assert!(detail.contains("256 fields"), "{detail}");
+    }
+
+    #[test]
+    fn details_echo_little_input() {
+        let one_byte = boc(cell(|builder| builder.write_num(&1_u8, 8)));
+        let name = "H".repeat(1_000);
+        let (kind, detail) = failure_of(&format!("a#_ x:{name} = A;"), &one_byte);
+        assert_eq!(kind, F::UnsupportedSchema);
+        assert!(detail.len() < 80, "{detail}");
+    }
+
+    proptest::proptest! {
+        #[test]
+        fn arbitrary_schemas_and_cells_never_panic(
+            schema in "[a-zA-Z0-9#$_:;=()\\[\\]{}^~?.+*!<> /\n]{0,512}",
+            tail in proptest::collection::vec(proptest::prelude::any::<u8>(), 0..64),
+        ) {
+            let mut raw = vec![0xb5, 0xee, 0x9c, 0x72];
+            raw.extend_from_slice(&tail);
+            let cells = [
+                DEMO_MESSAGE_CELL.to_owned(),
+                boc(wallet_cell(true)),
+                boc(TonCell::empty().clone()),
+                STANDARD.encode(raw),
+            ];
+            for cell in &cells {
+                let schema = schema.clone();
+                let cell = cell.clone();
+                proptest::prop_assert!(
+                    catch_unwind(move || decode_sign_data_cell(&schema, &cell, false)).is_ok()
+                );
+            }
+        }
+
+        #[test]
+        fn mutated_demo_cells_never_panic(
+            len in 0_u8..128,
+            text in proptest::collection::vec(proptest::prelude::any::<u8>(), 0..120),
+            extra_bits in 0_usize..8,
+            flip in proptest::prelude::any::<u16>(),
+        ) {
+            let built = cell(|builder| {
+                builder.write_num(&len, 7)?;
+                builder.write_bits(&text, text.len() * 8)?;
+                if extra_bits > 0 {
+                    let extra = u8::try_from(flip % 256).unwrap() >> (8 - extra_bits);
+                    builder.write_num(&extra, extra_bits)?;
+                }
+                Ok(())
+            });
+            let encoded = boc(built);
+            for schema in [DEMO_SCHEMA, WALLET_SCHEMA, ORDER_SCHEMA] {
+                let cell = encoded.clone();
+                let result = catch_unwind(move || decode_sign_data_cell(schema, &cell, true));
+                proptest::prop_assert!(result.is_ok());
+            }
+        }
+    }
+}
+
+#[cfg(test)]
+mod session_tests {
+    //! The decoder as Telegram reaches it: through `TonConnectDerivedSession`.
+
+    use std::str::FromStr as _;
+    use std::sync::Arc;
+
+    use base64::{Engine as _, engine::general_purpose::STANDARD};
+    use ton::ton_core::cell::{BoC, TonCell};
+    use ton::ton_core::traits::tlb::TLB as _;
+    use ton::ton_core::types::TonAddress;
+    use ton_connect_core::{ClientId, NetworkId, RawAccountAddress, test_boc};
+    use zeroize::Zeroizing;
+
+    use super::{TonConnectSignDataCellDecoding, TonConnectSignDataCellFailure};
+    use crate::TonConnectDerivedSession;
+
+    type TestResult = Result<(), Box<dyn std::error::Error>>;
+
+    /// Decoded `signData` cell entries as `(depth, name, value)`.
+    type CellFields = Vec<(u32, String, String)>;
+
+    /// The dApp client id of the derived-session fixed vector.
+    const PEER: &str = "8520f0098930a754748b7ddcb43ef75a0dbf3a0d26381af4eba4a98eaa9b4e6a";
+
+    const SESSION_ADDRESS: &str =
+        "0:1111111111111111111111111111111111111111111111111111111111111111";
+
+    const TESTNET: &str = "-3";
+    const MAINNET: &str = "-239";
+
+    const SIGN_DATA_SCHEMA: &str =
+        "message#_ len:uint7 {len <= 127} text:(bits len * 8) = Message;";
+
+    /// The demo dApp's `Message` cell (`len` 20, "Test message in cell") as it sends it.
+    const DEMO_MESSAGE_CELL: &str = "te6cckEBAQEAFwAAKSioyuboQNrK5ubCzspA0txAxsrY2Whv0fw=";
+
+    /// The demo dApp's current cell payload: 32 zero bits and "Hello!".
+    const DEMO_PAYLOAD: &str = "te6cckEBAQEADAAAFAAAAABIZWxsbyGVgYQo";
+
+    /// The demo dApp's destination and its mainnet non-bounceable form.
+    const DESTINATION_RAW: &str =
+        "0:8a5a9c7b70d329be670de4e6cce652d464765114aa98038c66c3d8ceaf2d19b0";
+    const NON_BOUNCEABLE: &str = "UQCKWpx7cNMpvmcN5ObM5lLUZHZRFKqYA4xmw9jOry0ZsAKJ";
+
+    fn session(network: &str) -> Arc<TonConnectDerivedSession> {
+        TonConnectDerivedSession::new(
+            Zeroizing::new([5_u8; 32]),
+            PEER.parse::<ClientId>().expect("fixed client id"),
+            [7_u8; 32],
+            RawAccountAddress::from_str(SESSION_ADDRESS).expect("raw address parses"),
+            NetworkId::try_from(network).expect("network id"),
+        )
+    }
+
+    fn decoded_cell_fields(
+        decoding: TonConnectSignDataCellDecoding,
+    ) -> Result<CellFields, Box<dyn std::error::Error>> {
+        match decoding {
+            TonConnectSignDataCellDecoding::Decoded { fields } => Ok(fields
+                .into_iter()
+                .map(|field| (field.depth, field.name, field.value))
+                .collect()),
+            TonConnectSignDataCellDecoding::NotDecodable { failure, detail } => {
+                Err(format!("cell is not decodable: {failure:?} {detail}").into())
+            }
+        }
+    }
+
+    /// A standard base64 `BoC` of `levels` data-less cells, each referencing the next one.
+    fn deep_chain_cell(levels: usize) -> String {
+        STANDARD.encode(test_boc::chain(levels))
+    }
+
+    /// Runs `job` on a 512 KiB stack: Telegram decrypts and decodes requests on a
+    /// default `std::thread`, which gets 512 KiB on macOS.
+    fn on_worker_stack(job: impl FnOnce() -> TestResult + Send + 'static) -> TestResult {
+        std::thread::Builder::new()
+            .name("wallet-worker-512k".into())
+            .stack_size(512 * 1024)
+            .spawn(move || job().map_err(|error| error.to_string()))
+            .expect("spawn")
+            .join()
+            .expect("the job must not panic")?;
+        Ok(())
+    }
+
+    #[test]
+    fn sign_data_cells_decode_through_the_session() -> TestResult {
+        let testnet = session(TESTNET);
+        assert_eq!(
+            decoded_cell_fields(
+                testnet.decode_sign_data_cell(
+                    SIGN_DATA_SCHEMA.to_owned(),
+                    DEMO_MESSAGE_CELL.to_owned()
+                )
+            )?,
+            [
+                (0, "len".to_owned(), "20".to_owned()),
+                (
+                    0,
+                    "text".to_owned(),
+                    "54657374206d65737361676520696e2063656c6c".to_owned()
+                ),
+            ]
+        );
+
+        let destination = TonAddress::from_str(DESTINATION_RAW)?;
+        let mut builder = TonCell::builder();
+        builder.write_num(&0b100_u8, 3)?;
+        builder.write_num(&0_u8, 8)?;
+        builder.write_bits(destination.hash.as_slice(), 256)?;
+        let cell = STANDARD.encode(BoC::new(builder.build()?).to_bytes(false)?);
+        let schema = "a#_ to:MsgAddress = A;";
+
+        let fields =
+            decoded_cell_fields(testnet.decode_sign_data_cell(schema.to_owned(), cell.clone()))?;
+        let expected = destination.to_base64(false, false, true);
+        assert!(expected.starts_with("0Q"), "{expected}");
+        assert_eq!(fields, [(0, "to".to_owned(), expected)]);
+
+        let fields =
+            decoded_cell_fields(session(MAINNET).decode_sign_data_cell(schema.to_owned(), cell))?;
+        assert_eq!(fields, [(0, "to".to_owned(), NON_BOUNCEABLE.to_owned())]);
+        Ok(())
+    }
+
+    #[test]
+    fn the_existing_demo_payload_is_not_a_message_cell() {
+        // 32 zero bits and "Hello!": `len` reads 0, then 73 bits are left over.
+        assert!(matches!(
+            session(TESTNET)
+                .decode_sign_data_cell(SIGN_DATA_SCHEMA.to_owned(), DEMO_PAYLOAD.to_owned()),
+            TonConnectSignDataCellDecoding::NotDecodable {
+                failure: TonConnectSignDataCellFailure::TrailingData,
+                ..
+            }
+        ));
+    }
+
+    #[test]
+    fn deep_sign_data_cells_stay_bounded_in_the_decoder_on_a_512_kib_stack() -> TestResult {
+        on_worker_stack(|| {
+            let session = session(TESTNET);
+            assert_eq!(
+                session.decode_sign_data_cell(SIGN_DATA_SCHEMA.to_owned(), deep_chain_cell(5000)),
+                TonConnectSignDataCellDecoding::NotDecodable {
+                    failure: TonConnectSignDataCellFailure::InvalidCell,
+                    detail: "cell is not a one-root BoC".to_owned(),
+                }
+            );
+
+            let schema = "c#_ v:^Cell = C;";
+            let TonConnectSignDataCellDecoding::NotDecodable { failure, detail } =
+                session.decode_sign_data_cell(schema.to_owned(), deep_chain_cell(1000))
+            else {
+                return Err("a 1 000-level cell value must reach the decoder's cap".into());
+            };
+            assert_eq!(
+                failure,
+                TonConnectSignDataCellFailure::LimitExceeded,
+                "{detail}"
+            );
+            assert!(detail.contains("256 cells"), "{detail}");
+
+            let short = deep_chain_cell(250);
+            let fields = decoded_cell_fields(
+                session.decode_sign_data_cell(schema.to_owned(), short.clone()),
+            )?;
+            let [(0, name, hex)] = fields.as_slice() else {
+                return Err(format!("one root field expected: {fields:?}").into());
+            };
+            assert_eq!(name, "v");
+            assert!(hex.starts_with("b5ee9c72"), "{hex}");
+            let bytes = hex
+                .as_bytes()
+                .chunks(2)
+                .map(|pair| Ok(u8::from_str_radix(std::str::from_utf8(pair)?, 16)?))
+                .collect::<Result<Vec<_>, Box<dyn std::error::Error>>>()?;
+            let root = TonCell::from_boc(STANDARD.decode(&short)?)?;
+            assert_eq!(TonCell::from_boc(bytes)?.hash()?, root.refs()[0].hash()?);
+            Ok(())
+        })
+    }
+}
