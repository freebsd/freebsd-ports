# New ports collection makefile for:	XFree86-fontEncodings
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	fontEncodings
PORTVERSION=	4.3.0
CATEGORIES=	x11-fonts
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	4.3.0
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X430src-4.tgz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	XFree86-4 font encoding files

BUILD_DEPENDS=	ucs2any:${PORTSDIR}/x11/XFree86-4-clients

CONFLICTS=	xorg-fonts-encodings-*

USE_IMAKE=		YES
PROJECTROOT=		-DProjectRoot=${PREFIX}
DIST_SUBDIR=		xc
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - xc/fonts/encodings
WRKSRC=			${WRKDIR}/xc/fonts/encodings

do-configure:
	(cd ${WRKSRC} && \
	 imake -DUseInstalled ${PROJECTROOT} -I${PREFIX}/lib/X11/config \
		-DTOPDIR=../../.. -DCURDIR=.; \
	 ${MAKE} Makefiles ; \
	 ${MAKE} includes ; \
	 ${MAKE} depend)

.include <bsd.port.pre.mk>
.if ${X_WINDOW_SYSTEM:L} != xfree86-4
IGNORE= is part of XFree86-4
.endif
.include <bsd.port.post.mk>
