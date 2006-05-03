# New ports collection makefile for:    xorg-dmx
# Date created:		13 Mar 2005
# Whom:			lesi@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xorg-dmx
PORTVERSION=	6.9.0
PORTREVISION=	1
CATEGORIES=	x11-servers
MASTER_SITES=	${MASTER_SITE_XORG}
MASTER_SITE_SUBDIR=	X11R${PORTVERSION}/src
DISTFILES=	X11R${PORTVERSION}-src1.tar.gz \
		X11R${PORTVERSION}-src3.tar.gz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Distributed Multihead X from X.Org

CONFLICTS=	XFree86-dmx-[0-9]*

EXTRA_PATCHES=	${CF_PATCHES} ${SERVER_PATCHES}

USE_XLIB=	yes

XBUILD_DIRS=	lib/font programs/Xserver/miext/damage programs/Xserver
XINCLUDE_DIRS=	lib/xtrans
XMAN_DIRS=	programs/Xserver/hw/dmx

MAN1=		Xdmx.1
PLIST_FILES=	bin/Xdmx

.include "${.CURDIR}/../../x11-servers/xorg-server/Makefile.inc"
.include <bsd.port.pre.mk>
.if ${X_WINDOW_SYSTEM:L} != xorg
IGNORE=	is part of X.Org and you have ${X_WINDOW_SYSTEM} set for X11\
	distribution. See The X Window System and Virtual Consoles chapter\
	of FAQ for more information
.endif
.include <bsd.port.post.mk>
