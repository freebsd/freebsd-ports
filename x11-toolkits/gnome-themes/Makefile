# New ports collection makefile for:	gnome-themes
# Date Created:				05 October 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome-themes
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.2
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	${X11BASE}/lib/gtk-2.0/2.2.0/engines/libthinice.so:${PORTSDIR}/x11-toolkits/gtk-thinice-engine \
		${X11BASE}/libdata/pkgconfig/gtk-engines-2.pc:${PORTSDIR}/x11-toolkits/gtk-engines2
LIB_DEPENDS=	metacity-private.0:${PORTSDIR}/x11-wm/metacity
RUN_DEPENDS=	${X11BASE}/lib/gtk-2.0/2.2.0/engines/libthinice.so:${PORTSDIR}/x11-toolkits/gtk-thinice-engine \
		${X11BASE}/libdata/pkgconfig/gtk-engines-2.pc:${PORTSDIR}/x11-toolkits/gtk-engines2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

.include <bsd.port.mk>
