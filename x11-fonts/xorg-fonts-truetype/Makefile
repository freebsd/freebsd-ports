# New ports collection makefile for:    xorg-fonts-truetype
# Date created:		30 May 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xorg-fonts-truetype
PORTVERSION=	6.7.0
CATEGORIES=	x11-fonts
MASTER_SITES=	http://freedesktop.org/~xorg/X11R6.7.0/src/
DISTNAME=	X11R6.7.0-src1

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org TrueType fonts

BUILD_DEPENDS=	ucs2any:${PORTSDIR}/x11/xorg-clients \
		fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/encodings/encodings.dir:${PORTSDIR}/x11-fonts/xorg-fonts-encodings \
		${X11BASE}/lib/X11/fonts/bitstream-vera/VeraIt.ttf:${PORTSDIR}/x11-fonts/bitstream-vera \
		fc-cache:${PORTSDIR}/x11-fonts/fontconfig

CONFLICTS=	XFree86-fontScalable-*

EXTRA_PATCHES=	${CF_PATCHES}

XBUILD_DIRS=	fonts/encodings fonts/scaled/TTF
XINSTALL_DIRS=	fonts/scaled/TTF

.include "${.CURDIR}/../../x11-servers/xorg-server/Makefile.inc"
.include <bsd.port.pre.mk>
.if ${X_WINDOW_SYSTEM:L} != xorg
IGNORE= is part of X.Org. For switching to X.Org, read UPDATING entry 20040723
.endif
.include <bsd.port.post.mk>
