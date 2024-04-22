PORTNAME=	Agda
PORTVERSION=	2.6.4.3
CATEGORIES=	math haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Dependently typed functional programming language and proof assistant
WWW=		https://wiki.portal.chalmers.se/agda/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	compiler goes out of memory

BUILD_DEPENDS=	emacs:editors/emacs@nox

USES=		cabal

USE_LOCALE=	en_US.UTF-8

PLIST_SUB=	AGDA_VER=${PORTVERSION}

USE_CABAL=	OneTuple-0.4.1.1_1 \
		QuickCheck-2.14.3 \
		STMonadTrans-0.4.8 \
		StateVar-1.2.2 \
		aeson-2.2.1.0_1 \
		alex-3.5.1.0 \
		ansi-terminal-1.1 \
		ansi-terminal-types-1.1 \
		assoc-1.1_1 \
		async-2.2.5 \
		base-compat-0.13.1 \
		base-orphans-0.9.1 \
		bifunctors-5.6.1_2 \
		blaze-builder-0.4.2.3 \
		blaze-html-0.9.2.0 \
		blaze-markup-0.8.3.0_1 \
		boxes-0.1.5 \
		case-insensitive-1.2.1.0 \
		colour-2.3.6 \
		comonad-5.0.8_2 \
		contravariant-1.5.5 \
		data-fix-0.3.2_5 \
		data-hash-0.2.0.1 \
		distributive-0.6.2.1_1 \
		dlist-1.0_1 \
		edit-distance-0.2.2.1_1 \
		equivalence-0.4.1 \
		generically-0.1.1_2 \
		gitrev-1.3.1 \
		happy-1.20.1.1 \
		hashable-1.4.3.0_1 \
		hsc2hs-0.68.10_1 \
		indexed-traversable-0.1.3 \
		indexed-traversable-instances-0.1.1.2_2 \
		integer-conversion-0.1.0.1_1 \
		integer-logarithms-1.0.3.1_5 \
		monad-control-1.0.3.1 \
		murmur-hash-0.1.0.10_1 \
		network-uri-2.6.4.2_1 \
		parallel-3.2.2.0_7 \
		peano-0.1.0.2 \
		primitive-0.9.0.0 \
		random-1.2.1.2 \
		regex-base-0.94.0.2_4 \
		regex-tdfa-1.3.2.2_2 \
		scientific-0.3.7.0_7 \
		semialign-1.3_1 \
		semigroupoids-6.0.0.1_1 \
		split-0.2.5 \
		splitmix-0.1.0.5 \
		strict-0.5_1 \
		tagged-0.8.8 \
		text-iso8601-0.1_1 \
		text-short-0.1.5_3 \
		th-abstraction-0.6.0.0_1 \
		th-compat-0.1.4_4 \
		these-1.2_1 \
		time-compat-1.9.6.1_6 \
		transformers-base-0.4.6 \
		transformers-compat-0.7.2 \
		unordered-containers-0.2.20_1 \
		uri-encode-1.5.0.7_3 \
		utf8-string-1.0.2 \
		uuid-types-1.0.5.1 \
		vector-0.13.1.0 \
		vector-hashtables-0.1.1.4 \
		vector-stream-0.1.0.1 \
		witherable-0.4.2_4 \
		zlib-0.7.0.0

CABAL_EXECUTABLES=	agda-mode agda
CABAL_WRAPPER_SCRIPTS=	${CABAL_EXECUTABLES}
agda_DATADIR_VARS=	Agda
agda-mode_DATADIR_VARS=	Agda

post-install:
	${SETENV} Agda_datadir=${WRKSRC}/src/data ${STAGEDIR}${PREFIX}/libexec/cabal/agda-mode compile
	${FIND} ${WRKSRC}/src/data/lib/prim/Agda -name '*.agda' -exec ${SETENV} Agda_datadir=${WRKSRC}/src/data ${STAGEDIR}${PREFIX}/libexec/cabal/agda {} \;
	${MKDIR} ${STAGEDIR}${DATADIR}/lib/prim/Agda
	cd ${WRKSRC}/src/data && ${COPYTREE_SHARE} lib ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/src/data && ${COPYTREE_SHARE} emacs-mode ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
