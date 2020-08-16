# $FreeBSD$

PORTNAME=	cryptol
DISTVERSION=	2.9.0
CATEGORIES=	security lang haskell

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Language of cryptography

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# https://github.com/GaloisInc/libBF-hs/issues/2
BROKEN_i386=	One of dependencies doesn't build on i386

USES=		cabal

USE_CABAL=	FloatingHex-0.4 \
		GraphSCC-1.0.4 \
		QuickCheck-2.14.1 \
		StateVar-1.2 \
		adjunctions-4.4_2 \
		alex-3.2.5 \
		ansi-terminal-0.10.3 \
		ansi-wl-pprint-0.6.9_1 \
		async-2.2.2_1 \
		attoparsec-0.13.2.4 \
		base-compat-0.11.1 \
		base-orphans-0.8.2 \
		bifunctors-5.5.7_1 \
		bimap-0.4.0_1 \
		bitwise-1.0.0.1_3 \
		blaze-builder-0.4.1.0 \
		blaze-html-0.9.1.2 \
		blaze-markup-0.8.2.7 \
		bv-sized-1.0.1 \
		bytestring-builder-0.10.8.2.0 \
		cabal-doctest-1.0.8_1 \
		call-stack-0.2.0 \
		case-insensitive-1.2.1.0 \
		clock-0.8 \
		colour-2.3.5 \
		comonad-5.0.6_1 \
		constraints-0.12 \
		contravariant-1.5.2 \
		crackNum-2.3 \
		cryptohash-sha1-0.11.100.1_5 \
		data-binary-ieee754-0.4.4 \
		deriving-compat-0.5.9 \
		distributive-0.6.2_2 \
		extra-1.7.4 \
		fingertree-0.1.4.2 \
		free-5.1.3_1 \
		generic-deriving-1.13.1 \
		gitrev-1.3.1 \
		happy-1.19.12 \
		hashable-1.3.0.0_1 \
		hashtables-1.2.3.4 \
		heredoc-0.2.0.0 \
		hsc2hs-0.68.7 \
		integer-logarithms-1.0.3_2 \
		invariant-0.5.3_1 \
		io-streams-1.5.1.0_1 \
		kan-extensions-5.2 \
		lens-4.19.2_1 \
		libBF-0.5.1 \
		megaparsec-8.0.0 \
		monad-control-1.0.2.3 \
		monadLib-3.10_1 \
		network-3.1.1.1 \
		panic-0.4.0.1 \
		parallel-3.2.2.0_2 \
		parameterized-utils-2.1.1 \
		parser-combinators-1.2.1 \
		primitive-0.7.1.0 \
		profunctors-5.5.2 \
		random-1.2.0 \
		reflection-2.1.6 \
		sbv-8.7 \
		scientific-0.3.6.2 \
		semigroupoids-5.3.4_1 \
		semigroups-0.19.1 \
		simple-smt-0.9.5 \
		splitmix-0.1 \
		strict-0.3.2 \
		syb-0.7.1 \
		tagged-0.8.6_2 \
		temporary-1.3 \
		tf-random-0.5 \
		th-abstraction-0.3.2.0 \
		th-lift-0.8.1 \
		transformers-base-0.4.5.2 \
		transformers-compat-0.6.5 \
		type-equality-1_1 \
		unordered-containers-0.2.12.0 \
		utf8-string-1.0.1.1_3 \
		vector-0.12.1.2 \
		versions-3.5.4 \
		void-0.7.3 \
		what4-1.0 \
		zenc-0.1.1 \
		zlib-0.6.2.2 \
		zlib-bindings-0.1.1.5_2

.include <bsd.port.mk>
