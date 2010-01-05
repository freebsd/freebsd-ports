# New ports collection makefile for: hs-GLURaw-ghc
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	GLURaw
PORTVERSION=	1.1.0.0
CATEGORIES=	x11-toolkits haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-
PKGNAMESUFFIX=	-ghc

MAINTAINER=	jacula@gmail.com
COMMENT=	A raw Haskell binding for the OpenGL Utility Toolkit

USE_GL=		glu

BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-OpenGLRaw-ghc>=1.1.0.1:${PORTSDIR}/x11-toolkits/hs-OpenGLRaw-ghc
RUN_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-OpenGLRaw-ghc>=1.1.0.1:${PORTSDIR}/x11-toolkits/hs-OpenGLRaw-ghc

GHC_VERSION=		6.10.4
HSGLURAW_VERSION=	${PORTVERSION}

GHC_CMD=	${LOCALBASE}/bin/ghc
SETUP_CMD=	./setup

DOCSDIR=		${PREFIX}/share/doc/${DISTNAME}
HSGLURAW_LIBDIR_REL=	lib/${DISTNAME}

PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		HSGLURAW_VERSION=${HSGLURAW_VERSION} \
		HSGLURAW_LIBDIR_REL=${HSGLURAW_LIBDIR_REL}

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
		     && ${SETUP_CMD} configure --haddock-options=-w --prefix=${PREFIX} \
		     				--extra-include-dirs=${LOCALBASE}/include \
						--extra-lib-dirs=${LOCALBASE}/lib

do-build:
	cd ${WRKSRC} && ${SETUP_CMD} build \
		     && ${SETUP_CMD} register --gen-script

.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${SETUP_CMD} haddock --hyperlink-source \
					     --hscolour-css=${HSCOLOUR_DATADIR}/hscolour.css
.endif

do-install:
	cd ${WRKSRC} && ${SETUP_CMD} install \
		     && ${INSTALL_SCRIPT} register.sh ${PREFIX}/${HSGLURAW_LIBDIR_REL}/register.sh

post-install:
	${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.mk>
