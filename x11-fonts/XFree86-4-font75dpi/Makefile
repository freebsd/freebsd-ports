# New ports collection makefile for:	XFree86-4-font75dpi
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	font75dpi
PORTVERSION=	4.0.3
CATEGORIES=	x11-fonts
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	4.0.2
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X402src-2.tgz

MAINTAINER=	taguchi@tohoku.iij.ad.jp

BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/encodings/encodings.dir:${PORTSDIR}/x11-fonts/XFree86-4-fontEncodings

XFREE86_VERSION=	4
USE_IMAKE=		YES
PROJECTROOT=		-DProjectRoot=${PREFIX}
DIST_SUBDIR=		xc
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - xc/fonts
WRKSRC=			${WRKDIR}/xc/fonts/bdf/75dpi

do-configure:
	(cd ${WRKDIR}/xc/fonts/encodings && \
	 imake -DUseInstalled ${PROJECTROOT} -I${PREFIX}/lib/X11/config \
		-DTOPDIR=../../.. -DCURDIR=.; \
	 ${MAKE} Makefiles ; \
	 ${MAKE} includes ; \
	 ${MAKE} depend)
	(cd ${WRKSRC} && \
	 imake -DUseInstalled ${PROJECTROOT} -I${PREFIX}/lib/X11/config \
		-DTOPDIR=../../.. -DCURDIR=.; \
	 ${MAKE} Makefiles ; \
	 ${MAKE} includes ; \
	 ${MAKE} depend)

pre-build:
	(cd ${WRKDIR}/xc/fonts/encodings && \
	 ${MAKE} all)

.include <bsd.port.mk>
