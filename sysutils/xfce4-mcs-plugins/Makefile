# New ports collection makefile for:	xfce-mcs-plugins
# Date created:		7 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-mcs-plugins
PORTVERSION=	4.2.1
PORTREVISION=	0
CATEGORIES=	sysutils xfce
MASTER_SITES=	http://www.us.xfce.org/archive/xfce-${PORTVERSION}/src/ \
		http://www.ca-us.xfce.org/archive/xfce-${PORTVERSION}/src/ \
		http://public.fh-wolfenbuettel.de/~luedickj/xfce4/xfce-${PORTVERSION}/ \
		http://hannelore.f1.fhtw-berlin.de/mirrors/xfce4/xfce-${PORTVERSION}/src/
DISTNAME=	xfce-mcs-plugins-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 settings manager plugins

BUILD_DEPENDS=	xfce-mcs-manager:${PORTSDIR}/sysutils/xfce4-mcs-manager
LIB_DEPENDS=	xfce4util.1:${PORTSDIR}/x11/libxfce4util \
		xfcegui4.3:${PORTSDIR}/x11-toolkits/libxfce4gui

USE_GETTEXT=	yes
USE_GNOME=	gtk20
USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CFLAGS=-I${LOCALBASE}/include \
		CPPFLAGS=-I${LOCALBASE}/include \
		LIBS=-L${LOCALBASE}/lib

.include <bsd.port.mk>
