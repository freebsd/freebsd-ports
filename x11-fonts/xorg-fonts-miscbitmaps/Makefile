# New ports collection makefile for:    xorg-fonts-miscbitmaps
# Date created:		30 May 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xorg-fonts-miscbitmaps
PORTVERSION=	6.9.0
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	${MASTER_SITE_XORG}
MASTER_SITE_SUBDIR=	X11R${PORTVERSION}/src
DISTNAME=	X11R${PORTVERSION}-src1

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org miscellaneous bitmap fonts

BUILD_DEPENDS=	ucs2any:${PORTSDIR}/x11/xorg-clients
RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/encodings/encodings.dir:${PORTSDIR}/x11-fonts/xorg-fonts-encodings

CONFLICTS=	XFree86-fontDefaultBitmaps-*

EXTRA_PATCHES=	${CF_PATCHES}

XBUILD_DIRS=	fonts/encodings fonts/bdf/misc
XINSTALL_DIRS=	fonts/bdf/misc

post-install:
	@command fc-cache -v ${PREFIX}/lib/X11/fonts/misc

.include "${.CURDIR}/../../x11-servers/xorg-server/Makefile.inc"
.include <bsd.port.pre.mk>
.if ${X_WINDOW_SYSTEM:L} != xorg
IGNORE=	is part of X.Org and you have ${X_WINDOW_SYSTEM} set for X11\
	distribution. See The X Window System and Virtual Consoles chapter\
	of FAQ for more information
.endif
.include <bsd.port.post.mk>
