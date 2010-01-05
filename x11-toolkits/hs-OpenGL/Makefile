# New ports collection makefile for:	hs-opengl-ghc
# Date created:				2008-09-04
# Whom:					Volker Stolz <vs@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	opengl
PORTVERSION=	2.4.0.1
CATEGORIES=	x11-toolkits haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/OpenGL/${PORTVERSION}/
PKGNAMEPREFIX=	hs-
PKGNAMESUFFIX=	-ghc
DISTNAME=	OpenGL-${PORTVERSION}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	OpenGL bindings for Haskell programs

BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-OpenGLRaw-ghc>=1.1.0.0:${PORTSDIR}/x11-toolkits/hs-OpenGLRaw-ghc \
		hs-GLURaw-ghc>=1.1.0.0:${PORTSDIR}/x11-toolkits/hs-GLURaw-ghc \
		hs-StateVar>=1.0.0.0:${PORTSDIR}/devel/hs-StateVar \
		hs-Tensor>=1.0.0.1:${PORTSDIR}/devel/hs-Tensor \
		hs-ObjectName>=1.0.0.0:${PORTSDIR}/devel/hs-ObjectName

RUN_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-OpenGLRaw-ghc>=1.1.0.0:${PORTSDIR}/x11-toolkits/hs-OpenGLRaw-ghc \
		hs-GLURaw-ghc>=1.1.0.0:${PORTSDIR}/x11-toolkits/hs-GLURaw-ghc \
		hs-StateVar>=1.0.0.0:${PORTSDIR}/devel/hs-StateVar \
		hs-Tensor>=1.0.0.1:${PORTSDIR}/devel/hs-Tensor \
		hs-ObjectName>=1.0.0.0:${PORTSDIR}/devel/hs-ObjectName

GHC_VERSION=		6.10.4
HSOPENGL_VERSION=	${PORTVERSION}

GHC_CMD=	${LOCALBASE}/bin/ghc
SETUP_CMD=	./setup

DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}
HSOPENGL_LIBDIR_REL=	lib/${DISTNAME}

PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		HSOPENGL_VERSION=${HSOPENGL_VERSION} \
		HSOPENGL_LIBDIR_REL=${HSOPENGL_LIBDIR_REL}

.if defined(NOPORTDOCS)
PLIST_SUB+=		NOPORTDOCS=""
.else
PLIST_SUB+=		NOPORTDOCS="@comment "
.endif

.if !defined(NOPORTDOCS)

PORT_HADDOCK!=	(cd  ${.CURDIR}/../../lang/ghc && ${MAKE} -V PORT_HADDOCK)
.if !empty(PORT_HADDOCK:M?0)
BUILD_DEPENDS+=	haddock:${PORTSDIR}/devel/hs-haddock
.endif
BUILD_DEPENDS+=	HsColour:${PORTSDIR}/print/hs-hscolour

HSCOLOUR_VERSION=	1.15
HSCOLOUR_DATADIR=	${PREFIX}/share/hscolour-${HSCOLOUR_VERSION}

PORTDOCS=	*
.endif

.SILENT:

do-configure:
	cd ${WRKSRC} && ${GHC_CMD} --make Setup.hs -o setup -package Cabal \
		     && ${SETUP_CMD} configure --haddock-options=-w --prefix=${PREFIX}

do-build:
	cd ${WRKSRC} && ${SETUP_CMD} build \
		     && ${SETUP_CMD} register --gen-script

.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${SETUP_CMD} haddock --hyperlink-source \
					     --hscolour-css=${HSCOLOUR_DATADIR}/hscolour.css
.endif

do-install:
	cd ${WRKSRC} && ${SETUP_CMD} install \
		     && ${INSTALL_SCRIPT} register.sh ${PREFIX}/${HSOPENGL_LIBDIR_REL}/register.sh

post-install:
	${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.mk>
