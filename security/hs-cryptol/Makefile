PORTNAME=	cryptol
DISTVERSION=	3.1.0
CATEGORIES=	security lang haskell

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Language of cryptography
WWW=		https://cryptol.net/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# https://github.com/GaloisInc/libBF-hs/issues/2
BROKEN_aarch64=	fails to build: src/LibBF/Mutable.hsc error: Couldn't match type `Int64' with `Int32'
BROKEN_i386=	One of dependencies doesn't build on i386

BUILD_DEPENDS=	ghc-9.2.8:lang/ghc92
RUN_DEPENDS=	z3:math/z3

USES=		cabal

CABAL_FLAGS=	-relocatable

USE_CABAL=	BoundedChan-1.0.3.0 \
		GraphSCC-1.0.4 \
		MemoTrie-0.6.11 \
		OneTuple-0.4.1.1_1 \
		QuickCheck-2.14.3 \
		StateVar-1.2.2 \
		adjunctions-4.4.2_2 \
		aeson-2.2.1.0_1 \
		alex-3.5.0.0 \
		ansi-terminal-1.0.2 \
		ansi-terminal-types-0.11.5_1 \
		arithmoi-0.13.0.0_3 \
		assoc-1.1_1 \
		async-2.2.5 \
		attoparsec-0.14.4_5 \
		base-compat-0.12.3 \
		base-compat-batteries-0.12.3 \
		base-orphans-0.9.1 \
		bifunctors-5.6.1_2 \
		bimap-0.5.0 \
		bitwise-1.0.0.1_9 \
		blaze-builder-0.4.2.3 \
		blaze-html-0.9.1.2_4 \
		blaze-markup-0.8.3.0_1 \
		boring-0.2.1_1 \
		bv-sized-1.0.5_1 \
		call-stack-0.4.0 \
		case-insensitive-1.2.1.0 \
		chimera-0.4.0.0 \
		clock-0.8.4 \
		colour-2.3.6 \
		comonad-5.0.8_2 \
		concurrent-extra-0.7.0.12 \
		config-value-0.8.3_5 \
		constraints-0.14 \
		contravariant-1.5.5 \
		criterion-measurement-0.2.1.0 \
		cryptohash-sha1-0.11.101.0_3 \
		data-array-byte-0.1.0.1_2 \
		data-fix-0.3.2_5 \
		deriving-compat-0.6.5_1 \
		distributive-0.6.2.1_1 \
		dlist-1.0_1 \
		exact-pi-0.5.0.2 \
		extra-1.7.14 \
		fingertree-0.1.5.0 \
		foldable1-classes-compat-0.1_4 \
		free-5.2_3 \
		generically-0.1.1_2 \
		gitrev-1.3.1 \
		happy-1.20.1.1 \
		hashable-1.4.3.0_1 \
		hashtables-1.3.1 \
		haskell-lexer-1.1.1 \
		heredoc-0.2.0.0 \
		hgmp-0.1.2.1_2 \
		hsc2hs-0.68.10_1 \
		ieee754-0.8.0 \
		indexed-traversable-0.1.3 \
		indexed-traversable-instances-0.1.1.2_2 \
		infinite-list-0.1.1 \
		integer-conversion-0.1.0.1_1 \
		integer-logarithms-1.0.3.1_5 \
		integer-roots-1.0.2.0_1 \
		invariant-0.6.2_1 \
		io-streams-1.5.2.2_3 \
		kan-extensions-5.2.5_2 \
		language-c99-0.2.0 \
		language-c99-simple-0.3.0 \
		language-c99-util-0.2.0 \
		lens-5.2.3_2 \
		libBF-0.6.7 \
		libffi-0.2.1 \
		megaparsec-9.6.1 \
		mod-0.2.0.1 \
		monad-control-1.0.3.1 \
		monadLib-3.10.1 \
		network-3.1.4.0_1 \
		network-uri-2.6.4.2_1 \
		newtype-generics-0.6.2_2 \
		numtype-dk-0.5.0.3 \
		optparse-applicative-0.18.1.0 \
		ordered-containers-0.2.3 \
		panic-0.4.0.1 \
		parallel-3.2.2.0_7 \
		parameterized-utils-2.1.8.0 \
		parser-combinators-1.3.0_1 \
		pretty-show-1.10 \
		prettyprinter-1.7.1 \
		prettyprinter-ansi-terminal-1.1.3 \
		primitive-0.9.0.0 \
		profunctors-5.6.2_3 \
		random-1.2.1.2 \
		reflection-2.1.7_1 \
		s-cargot-0.1.6.0 \
		safe-exceptions-0.1.7.4_1 \
		sbv-10.2_1 \
		scientific-0.3.7.0_7 \
		semialign-1.3_1 \
		semigroupoids-6.0.0.1_1 \
		semigroups-0.20 \
		semirings-0.6_1 \
		simple-smt-0.9.7 \
		splitmix-0.1.0.5 \
		strict-0.5_1 \
		syb-0.7.2.4 \
		tagged-0.8.8 \
		temporary-1.3 \
		text-iso8601-0.1_1 \
		text-short-0.1.5_3 \
		tf-random-0.5 \
		th-abstraction-0.6.0.0_1 \
		th-compat-0.1.4_4 \
		th-lift-0.8.4 \
		th-lift-instances-0.1.20 \
		these-1.2_1 \
		time-compat-1.9.6.1_6 \
		transformers-base-0.4.6 \
		transformers-compat-0.7.2 \
		type-equality-1_6 \
		unbounded-delays-0.1.1.1 \
		uniplate-1.6.13_1 \
		unliftio-0.2.25.0 \
		unliftio-core-0.2.1.0_3 \
		unordered-containers-0.2.20_1 \
		utf8-string-1.0.2 \
		uuid-types-1.0.5.1 \
		vector-0.13.1.0 \
		vector-stream-0.1.0.1 \
		versions-6.0.5 \
		void-0.7.3 \
		what4-1.5.1 \
		witherable-0.4.2_4 \
		zenc-0.1.2 \
		zlib-0.6.3.0_4 \
		zlib-bindings-0.1.1.5_2

CABAL_EXECUTABLES=	cryptol cryptol-html
CABAL_WRAPPER_SCRIPTS=	${CABAL_EXECUTABLES}

post-install:
	cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
