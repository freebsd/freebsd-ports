# New ports collection makefile for:	XFree86-font100dpi
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	font100dpi
PORTVERSION=	4.4.0
CATEGORIES=	x11-fonts
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	${PORTVERSION}
PKGNAMEPREFIX=	XFree86-
DISTFILES=	XFree86-4.4.0-src-4.tgz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	XFree86-4 bitmap 100 dpi fonts

BUILD_DEPENDS=	ucs2any:${PORTSDIR}/x11/XFree86-4-clients
RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/encodings/encodings.dir:${PORTSDIR}/x11-fonts/XFree86-4-fontEncodings

CONFLICTS=	xorg-fonts-100dpi-*

USE_IMAKE=		YES
PROJECTROOT=		-DProjectRoot=${PREFIX}
DIST_SUBDIR=		xc
WRKSRC=			${WRKDIR}/xc/fonts/bdf/100dpi

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

.include <bsd.port.pre.mk>
.if ${X_WINDOW_SYSTEM:L} != xfree86-4
IGNORE= is part of XFree86-4
.endif
.include <bsd.port.post.mk>
