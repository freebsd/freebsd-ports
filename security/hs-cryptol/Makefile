PORTNAME=	cryptol
DISTVERSION=	3.4.0
CATEGORIES=	security lang haskell

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Domain-specific language for specifying cryptographic algorithms
WWW=		https://cryptol.net \
		https://github.com/GaloisInc/cryptol

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# https://github.com/GaloisInc/libBF-hs/issues/2
BROKEN_aarch64=	fails to build: src/LibBF/Mutable.hsc error: Couldn't match type `Int64' with `Int32'
BROKEN_i386=	one of dependencies doesn't build on i386

RUN_DEPENDS=	z3:math/z3

USES=		cabal

USE_CABAL=	BoundedChan-1.0.3.0 \
		GraphSCC-1.0.4 \
		MemoTrie-0.6.11 \
		OneTuple-0.4.2_1 \
		QuickCheck-2.16.0.0 \
		StateVar-1.2.2 \
		adjunctions-4.4.3 \
		aeson-2.2.3.0_4 \
		alex-3.5.4.0 \
		ansi-terminal-1.1.3 \
		ansi-terminal-types-1.1.3 \
		arithmoi-0.13.2.0 \
		assoc-1.1.1_1 \
		async-2.2.5_3 \
		attoparsec-0.14.4_6 \
		barbies-2.1.1.0 \
		base-compat-0.12.3 \
		base-orphans-0.9.3 \
		bifunctors-5.6.2_2 \
		bimap-0.5.0 \
		bitvec-1.1.5.0_3 \
		bitwise-1.0.0.1_11 \
		blaze-builder-0.4.4.1 \
		blaze-html-0.9.2.0_1 \
		blaze-markup-0.8.3.0_2 \
		boring-0.2.2_1 \
		bv-sized-1.0.6 \
		call-stack-0.4.0 \
		case-insensitive-1.2.1.0 \
		character-ps-0.1 \
		chimera-0.4.1.0_1 \
		clock-0.8.4 \
		colour-2.3.6 \
		comonad-5.0.9_1 \
		concurrent-extra-0.7.0.12 \
		concurrent-output-1.10.21 \
		config-value-0.8.3_9 \
		constraints-0.14.2_1 \
		contravariant-1.5.5 \
		criterion-measurement-0.2.3.0 \
		cryptohash-sha256-0.11.102.1_6 \
		data-fix-0.3.4_1 \
		deriving-compat-0.6.7_1 \
		distributive-0.6.2.1_1 \
		dlist-1.0_2 \
		erf-2.0.0.0 \
		exact-pi-0.5.0.2 \
		extra-1.8 \
		file-embed-0.0.16.0 \
		fingertree-0.1.6.2 \
		free-5.2_7 \
		generically-0.1.1_4 \
		gitrev-1.3.1 \
		happy-2.1.7 \
		happy-lib-2.1.7 \
		hashable-1.5.0.0_1 \
		hashtables-1.4.2 \
		haskell-lexer-1.2.1 \
		hedgehog-1.7 \
		heredoc-0.2.0.0 \
		hgmp-0.1.2.1_2 \
		hsc2hs-0.68.10_4 \
		ieee754-0.8.0 \
		indexed-traversable-0.1.4_1 \
		indexed-traversable-instances-0.1.2_1 \
		infinite-list-0.1.2 \
		integer-conversion-0.1.1_1 \
		integer-logarithms-1.0.4 \
		integer-roots-1.0.3.0 \
		invariant-0.6.4_1 \
		io-streams-1.5.2.2_6 \
		kan-extensions-5.2.7 \
		language-c99-0.2.0 \
		language-c99-simple-0.3.0 \
		language-c99-util-0.2.0 \
		lens-5.3.5_1 \
		libBF-0.6.8 \
		libffi-0.2.1 \
		lifted-async-0.11.0 \
		lifted-base-0.2.3.12 \
		megaparsec-9.7.0 \
		mmorph-1.2.1_1 \
		mod-0.2.1.0 \
		monad-control-1.0.3.1 \
		monadLib-3.10.3 \
		network-3.2.8.0 \
		network-uri-2.6.4.2_1 \
		newtype-generics-0.6.2_5 \
		numtype-dk-0.5.0.3 \
		optparse-applicative-0.19.0.0 \
		ordered-containers-0.2.4 \
		os-string-2.0.8 \
		panic-0.4.0.1 \
		parallel-3.3.0.0 \
		parameterized-utils-2.1.11.0 \
		parser-combinators-1.3.0_1 \
		pretty-show-1.10 \
		prettyprinter-1.7.1 \
		prettyprinter-ansi-terminal-1.1.3 \
		primitive-0.9.1.0 \
		profunctors-5.6.3 \
		random-1.3.1 \
		reflection-2.1.9_1 \
		resourcet-1.3.0 \
		rme-0.1.1 \
		rme-what4-0.1.1 \
		s-cargot-0.1.6.0 \
		safe-exceptions-0.1.7.4_1 \
		sbv-10.10 \
		scientific-0.3.8.0_2 \
		semialign-1.3.1_2 \
		semigroupoids-6.0.1_2 \
		semigroups-0.20 \
		semirings-0.7 \
		simple-smt-0.9.8 \
		splitmix-0.1.3.1 \
		strict-0.5.1_1 \
		syb-0.7.3 \
		tagged-0.8.9 \
		tasty-1.5.3_2 \
		tasty-hedgehog-1.4.0.2_7 \
		tasty-hunit-0.10.2 \
		temporary-1.3 \
		terminal-size-0.3.4_1 \
		text-iso8601-0.1.1_2 \
		text-short-0.1.6_3 \
		tf-random-0.5 \
		th-abstraction-0.7.1.0_1 \
		th-compat-0.1.6 \
		th-lift-0.8.6 \
		th-lift-instances-0.1.20 \
		these-1.2.1_2 \
		time-compat-1.9.8 \
		toml-parser-2.0.1.2_1 \
		transformers-base-0.4.6 \
		transformers-compat-0.7.2 \
		unbounded-delays-0.1.1.1 \
		uniplate-1.6.13_1 \
		unliftio-0.2.25.1 \
		unliftio-core-0.2.1.0_4 \
		unordered-containers-0.2.20.1 \
		uuid-types-1.0.6_3 \
		vector-0.13.2.0_2 \
		vector-stream-0.1.0.1_4 \
		versions-6.0.8 \
		void-0.7.3 \
		what4-1.7.1.0 \
		witherable-0.5_1 \
		wl-pprint-annotated-0.1.0.1_4 \
		zenc-0.1.2 \
		zlib-0.7.1.1 \
		zlib-bindings-0.1.1.5_2

CABAL_FLAGS=		-relocatable
CABAL_EXECUTABLES=	cryptol cryptol-html
CABAL_WRAPPER_SCRIPTS=	${CABAL_EXECUTABLES}

post-install:
	cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
