PORTNAME=	Agda
DISTVERSION=	2.8.0.2
CATEGORIES=	math haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Dependently typed functional programming language and proof assistant
WWW=		https://wiki.portal.chalmers.se/agda/ \
		https://hackage.haskell.org/package/Agda

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	emacs:editors/emacs@nox

USES=		cabal

CABAL_EXECUTABLES=	agda agda-mode
CABAL_WRAPPER_SCRIPTS=	${CABAL_EXECUTABLES}
agda_DATADIR_VARS=	Agda
agda-mode_DATADIR_VARS=	Agda

PLIST_SUB=	AGDA_VER=${DISTVERSION}

post-install:
	#${SETENV} Agda_datadir=${WRKSRC}/src/data ${STAGEDIR}${PREFIX}/libexec/cabal/agda-mode compile
	${FIND} ${WRKSRC}/src/data/lib/prim/Agda -name '*.agda' -exec ${SETENV} Agda_datadir=${WRKSRC}/src/data ${STAGEDIR}${PREFIX}/libexec/cabal/agda {} \;
	${MKDIR} ${STAGEDIR}${DATADIR}/lib/prim/Agda
	cd ${WRKSRC}/src/data && ${COPYTREE_SHARE} lib ${STAGEDIR}${DATADIR}
	#cd ${WRKSRC}/src/data && ${COPYTREE_SHARE} emacs-mode ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
