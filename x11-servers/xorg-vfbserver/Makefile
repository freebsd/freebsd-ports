# New ports collection makefile for:    xorg-vfbserver
# Date created:		17 June 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xorg-vfbserver
PORTVERSION=	6.7.0
CATEGORIES=	x11-servers
MASTER_SITES=	http://freedesktop.org/~xorg/X11R6.7.0/src/
DISTFILES=	X11R6.7.0-src1.tar.gz \
		X11R6.7.0-src3.tar.gz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X virtual framebuffer server from X.Org

CONFLICTS=	XFree86-VirtualFramebufferServer-*

EXTRA_PATCHES=	${CF_PATCHES} ${SERVER_PATCHES}

USE_XLIB=	yes

XBUILD_DIRS=	lib/font programs/Xserver
XINCLUDE_DIRS=	lib/xtrans
XMAN_DIRS=	programs/Xserver

MAN1=		Xvfb.1

.include "${.CURDIR}/../../x11-servers/xorg-server/Makefile.inc"
.include <bsd.port.pre.mk>
.if ${X_WINDOW_SYSTEM:L} != xorg
IGNORE= is part of X.Org
.endif
.include <bsd.port.post.mk>
