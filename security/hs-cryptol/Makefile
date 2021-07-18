PORTNAME=	cryptol
DISTVERSION=	2.11.0
CATEGORIES=	security lang haskell

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Language of cryptography

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# https://github.com/GaloisInc/libBF-hs/issues/2
BROKEN_i386=	One of dependencies doesn't build on i386

RUN_DEPENDS=	z3:math/z3

USES=		cabal

USE_CABAL=	FloatingHex-0.5 \
		GraphSCC-1.0.4 \
		MemoTrie-0.6.10 \
		QuickCheck-2.14.2 \
		StateVar-1.2.1 \
		adjunctions-4.4_2 \
		alex-3.2.6 \
		ansi-terminal-0.11 \
		ansi-wl-pprint-0.6.9_2 \
		assoc-1.0.2_1 \
		async-2.2.3 \
		attoparsec-0.13.2.5_1 \
		base-compat-0.11.2 \
		base-orphans-0.8.4 \
		bifunctors-5.5.10 \
		bimap-0.4.0_1 \
		bitwise-1.0.0.1_4 \
		blaze-builder-0.4.2.1 \
		blaze-html-0.9.1.2_1 \
		blaze-markup-0.8.2.8 \
		bv-sized-1.0.2 \
		bytestring-builder-0.10.8.2.0 \
		call-stack-0.3.0 \
		case-insensitive-1.2.1.0 \
		clock-0.8.2 \
		colour-2.3.5 \
		comonad-5.0.8 \
		config-value-0.8.1_1 \
		constraints-0.13 \
		contravariant-1.5.3 \
		cryptohash-sha1-0.11.100.1_5 \
		data-binary-ieee754-0.4.4 \
		deriving-compat-0.5.10 \
		distributive-0.6.2.1 \
		extra-1.7.9 \
		fingertree-0.1.4.2 \
		free-5.1.6 \
		gitrev-1.3.1 \
		happy-1.20.0 \
		hashable-1.3.1.0 \
		hashtables-1.2.4.1 \
		heredoc-0.2.0.0 \
		hsc2hs-0.68.7_1 \
		indexed-traversable-0.1.1 \
		indexed-traversable-instances-0.1 \
		integer-logarithms-1.0.3.1 \
		invariant-0.5.4 \
		io-streams-1.5.2.0_2 \
		kan-extensions-5.2.2 \
		lens-5.0.1 \
		libBF-0.6.2 \
		megaparsec-9.0.1_1 \
		monad-control-1.0.2.3 \
		monadLib-3.10_1 \
		network-3.1.2.1_1 \
		newtype-generics-0.6 \
		optparse-applicative-0.16.1.0 \
		panic-0.4.0.1 \
		parallel-3.2.2.0_3 \
		parameterized-utils-2.1.3.0 \
		parser-combinators-1.3.0 \
		prettyprinter-1.7.0 \
		primitive-0.7.1.0_2 \
		profunctors-5.6.2 \
		random-1.2.0_5 \
		reflection-2.1.6 \
		sbv-8.12 \
		scientific-0.3.6.2 \
		semigroupoids-5.3.5 \
		semigroups-0.19.1 \
		simple-smt-0.9.6 \
		splitmix-0.1.0.3 \
		strict-0.4.0.1 \
		syb-0.7.2.1 \
		tagged-0.8.6.1_1 \
		temporary-1.3 \
		tf-random-0.5 \
		th-abstraction-0.4.2.0 \
		th-lift-0.8.2 \
		th-lift-instances-0.1.18 \
		these-1.1.1.1_1 \
		transformers-base-0.4.5.2 \
		transformers-compat-0.6.6 \
		type-equality-1_2 \
		uniplate-1.6.13_1 \
		unordered-containers-0.2.13.0 \
		utf8-string-1.0.2 \
		vector-0.12.3.0 \
		versions-4.0.3 \
		void-0.7.3 \
		what4-1.1 \
		zenc-0.1.1 \
		zlib-0.6.2.3 \
		zlib-bindings-0.1.1.5_2

.include <bsd.port.mk>
