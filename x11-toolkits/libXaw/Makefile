# New ports collection makefile for:   libXaw
# Date Created:			25 Jan, 2003
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libXaw
PORTVERSION=	7.0.2
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://pdx.freedesktop.org/~xlibs/release/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Athena Widgets library

LIB_PC_DEPENDS=	${X11BASE}/libdata/pkgconfig/x11.pc:${PORTSDIR}/x11/libX11 \
		${X11BASE}/libdata/pkgconfig/xt.pc:${PORTSDIR}/x11-toolkits/libXt \
		${X11BASE}/libdata/pkgconfig/xmu.pc:${PORTSDIR}/x11-toolkits/libXmu \
		${X11BASE}/libdata/pkgconfig/xpm.pc:${PORTSDIR}/x11/libXpm
BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/xproto.pc:${PORTSDIR}/x11/xproto \
		${X11BASE}/libdata/pkgconfig/xextensions.pc:${PORTSDIR}/x11/xextensions \
		${LIB_PC_DEPENDS}
RUN_DEPENDS=	${LIB_PC_DEPENDS}

CONFLICTS=	XFree86-libraries-* xorg-libraries-*

USE_BZIP2=	yes
PREFIX?=	${X11BASE}
MTREE_FILE=	/etc/mtree/BSD.x11-4.dist
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
USE_LIBTOOL_VER=13
CFLAGS+=	-DMALLOC_0_RETURNS_NULL
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack pkgconfig

MAN3=		Xaw.3

.include <bsd.port.mk>
