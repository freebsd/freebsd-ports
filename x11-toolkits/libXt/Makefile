# New ports collection makefile for:   libXt
# Date Created:			25 Jan, 2003
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libXt
PORTVERSION=	0.1.4
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://pdx.freedesktop.org/~xlibs/release/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Toolkit library

LIB_PC_DEPENDS=	${X11BASE}/libdata/pkgconfig/x11.pc:${PORTSDIR}/x11/libX11
BUILD_DEPENDS=	${LIB_PC_DEPENDS}
RUN_DEPENDS=	${LIB_PC_DEPENDS}

USE_BZIP2=	yes
PREFIX?=	${X11BASE}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LIBTOOL=	yes
CFLAGS+=	-DMALLOC_0_RETURNS_NULL
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack pkgconfig

.include <bsd.port.mk>
