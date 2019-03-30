# $FreeBSD$

PORTNAME=	Agda-stdlib
DISTVERSION=	0.16

DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	math haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Agda standard library

LICENSE=	MIT

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_GITHUB=	yes

GH_ACCOUNT=	agda
GH_PROJECT=	agda-stdlib

USE_CABAL=	Agda filemanip>=0.3

STANDALONE=	yes

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"

do-build:
	cd ${WRKSRC} && ( \
	    ${SETENV} ${MAKE_ENV} ${SETUP_CMD} build; \
	    dist/build/GenerateEverything/GenerateEverything; \
	    agda -i. -isrc README.agda \
	)
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC} && agda -i. -isrc --html README.agda -v0
.endif

do-install:
	cd ${WRKSRC} && ( \
	    ${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DATADIR}; \
	    ${INSTALL_DATA} LICENCE ${STAGEDIR}${DOCSDIR}; \
	    cd src && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR} \
	)
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
