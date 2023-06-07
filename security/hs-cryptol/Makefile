PORTNAME=	cryptol
DISTVERSION=	2.13.0
PORTREVISION=	1
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

USE_CABAL=	GraphSCC-1.0.4 \
		MemoTrie-0.6.10 \
		OneTuple-0.3.1_3 \
		QuickCheck-2.14.2 \
		StateVar-1.2.2 \
		adjunctions-4.4.2 \
		alex-3.2.7.1 \
		ansi-terminal-0.11.3 \
		ansi-wl-pprint-0.6.9_3 \
		arithmoi-0.12.0.2 \
		assoc-1.0.2_3 \
		async-2.2.4_2 \
		attoparsec-0.14.4_2 \
		base-compat-0.12.2 \
		base-compat-batteries-0.12.2 \
		base-orphans-0.8.7 \
		bifunctors-5.5.13 \
		bimap-0.5.0 \
		bitwise-1.0.0.1_5 \
		blaze-builder-0.4.2.2_1 \
		blaze-html-0.9.1.2_2 \
		blaze-markup-0.8.2.8_3 \
		bv-sized-1.0.4 \
		call-stack-0.4.0 \
		case-insensitive-1.2.1.0 \
		chimera-0.3.2.0 \
		clock-0.8.3 \
		colour-2.3.6 \
		comonad-5.0.8_1 \
		concurrent-extra-0.7.0.12 \
		config-value-0.8.3 \
		constraints-0.13.4 \
		contravariant-1.5.5 \
		cryptohash-sha1-0.11.101.0_1 \
		data-binary-ieee754-0.4.4 \
		deriving-compat-0.6.1_1 \
		distributive-0.6.2.1_1 \
		exact-pi-0.5.0.2 \
		extra-1.7.12 \
		fingertree-0.1.5.0 \
		free-5.1.9_1 \
		gitrev-1.3.1 \
		happy-1.20.0_1 \
		hashable-1.3.5.0_1 \
		hashtables-1.2.4.2 \
		heredoc-0.2.0.0 \
		hsc2hs-0.68.8_1 \
		indexed-traversable-0.1.2_2 \
		indexed-traversable-instances-0.1.1.1 \
		integer-logarithms-1.0.3.1_3 \
		integer-roots-1.0.2.0 \
		invariant-0.6_1 \
		io-streams-1.5.2.2 \
		kan-extensions-5.2.5 \
		lens-5.1.1_1 \
		libBF-0.6.5.1 \
		megaparsec-9.2.2 \
		mod-0.1.2.2 \
		monad-control-1.0.3.1 \
		monadLib-3.10.1 \
		network-3.1.2.7 \
		newtype-generics-0.6.2_1 \
		numtype-dk-0.5.0.3 \
		optparse-applicative-0.17.0.0 \
		panic-0.4.0.1 \
		parallel-3.2.2.0_5 \
		parameterized-utils-2.1.5.0 \
		parser-combinators-1.3.0 \
		prettyprinter-1.7.1 \
		primitive-0.7.4.0 \
		profunctors-5.6.2_2 \
		random-1.2.1.1 \
		reflection-2.1.6_1 \
		sbv-9.0 \
		scientific-0.3.7.0_3 \
		semigroupoids-5.3.7 \
		semigroups-0.20 \
		semirings-0.6_1 \
		simple-smt-0.9.7 \
		splitmix-0.1.0.4_1 \
		strict-0.4.0.1_4 \
		syb-0.7.2.2 \
		tagged-0.8.6.1_3 \
		temporary-1.3 \
		tf-random-0.5 \
		th-abstraction-0.4.5.0 \
		th-lift-0.8.2_2 \
		th-lift-instances-0.1.20 \
		these-1.1.1.1_6 \
		transformers-base-0.4.6 \
		transformers-compat-0.7.2 \
		type-equality-1_4 \
		unbounded-delays-0.1.1.1 \
		uniplate-1.6.13_1 \
		unordered-containers-0.2.19.1_1 \
		utf8-string-1.0.2 \
		vector-0.12.3.1_2 \
		versions-5.0.4 \
		void-0.7.3 \
		what4-1.3 \
		zenc-0.1.2 \
		zlib-0.6.3.0 \
		zlib-bindings-0.1.1.5_2

CABAL_EXECUTABLES=	cryptol cryptol-html
CABAL_WRAPPER_SCRIPTS=	${CABAL_EXECUTABLES}

post-install:
	cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
