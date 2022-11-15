PORTNAME=	Agda
PORTVERSION=	2.6.2.2
PORTREVISION=	3
CATEGORIES=	math haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Dependently typed functional programming language and proof assistant
WWW=		https://wiki.portal.chalmers.se/agda/

LICENSE=	UNKNOWN
LICENSE_NAME=	custom
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

BROKEN_i386=	Compiler goes out of memory

BUILD_DEPENDS=	emacs:editors/emacs

USES=		cabal

USE_LOCALE=	en_US.UTF-8

USE_CABAL=	OneTuple-0.3.1_3 \
		QuickCheck-2.14.2 \
		STMonadTrans-0.4.6_1 \
		StateVar-1.2.2 \
		aeson-2.0.3.0 \
		alex-3.2.7.1 \
		assoc-1.0.2_3 \
		async-2.2.4_2 \
		attoparsec-0.14.4_2 \
		base-compat-0.12.2 \
		base-compat-batteries-0.12.2 \
		base-orphans-0.8.7 \
		bifunctors-5.5.13 \
		blaze-builder-0.4.2.2_1 \
		blaze-html-0.9.1.2_2 \
		blaze-markup-0.8.2.8_3 \
		boxes-0.1.5 \
		case-insensitive-1.2.1.0 \
		comonad-5.0.8_1 \
		contravariant-1.5.5 \
		data-fix-0.3.2_3 \
		data-hash-0.2.0.1 \
		distributive-0.6.2.1_1 \
		dlist-1.0 \
		edit-distance-0.2.2.1_1 \
		equivalence-0.4.1 \
		generically-0.1 \
		gitrev-1.3.1 \
		happy-1.20.0_1 \
		hashable-1.4.1.0 \
		hashtables-1.3.1 \
		indexed-traversable-0.1.2_2 \
		indexed-traversable-instances-0.1.1.1 \
		integer-logarithms-1.0.3.1_3 \
		monad-control-1.0.3.1 \
		murmur-hash-0.1.0.10 \
		network-uri-2.6.4.1 \
		parallel-3.2.2.0_5 \
		primitive-0.7.4.0 \
		random-1.2.1.1 \
		regex-base-0.94.0.2_1 \
		regex-tdfa-1.3.2 \
		scientific-0.3.7.0_3 \
		semialign-1.2.0.1_3 \
		semigroupoids-5.3.7 \
		split-0.2.3.5 \
		splitmix-0.1.0.4_1 \
		strict-0.4.0.1_4 \
		tagged-0.8.6.1_3 \
		text-short-0.1.5_1 \
		th-abstraction-0.4.5.0 \
		th-compat-0.1.4 \
		these-1.1.1.1_6 \
		time-compat-1.9.6.1_4 \
		transformers-base-0.4.6 \
		transformers-compat-0.7.2 \
		unordered-containers-0.2.19.1_1 \
		uri-encode-1.5.0.7_2 \
		utf8-string-1.0.2 \
		uuid-types-1.0.5_3 \
		vector-0.12.3.1_1 \
		vector-stream-0.1.0.0_1 \
		witherable-0.4.2_3 \
		zlib-0.6.3.0

CABAL_EXECUTABLES=	agda-mode agda
CABAL_WRAPPER_SCRIPTS=	${CABAL_EXECUTABLES}
agda_DATADIR_VARS=	Agda
agda-mode_DATADIR_VARS=	Agda

post-install:
	${SETENV} Agda_datadir=${WRKSRC}/src/data ${STAGEDIR}${PREFIX}/libexec/cabal/agda-mode compile
	find ${WRKSRC}/src/data/lib/prim/Agda -name '*.agda' -exec ${SETENV} Agda_datadir=${WRKSRC}/src/data ${STAGEDIR}${PREFIX}/libexec/cabal/agda {} \;
	${MKDIR} ${STAGEDIR}${DATADIR}/lib/prim/Agda
	cd ${WRKSRC}/src/data && ${COPYTREE_SHARE} lib ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/src/data && ${COPYTREE_SHARE} emacs-mode ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
