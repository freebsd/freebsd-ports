# New ports collection makefile for:	libxfce4util
# Date created:		7 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-utils
PORTVERSION=	3.99.2
PORTREVISION=   1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.xfce.org/archive/xfce4-rc2/src/ \
		ftp://ftp.unix-ag.org/user/bmeurer/xfce4/rc2/separate/ \
		http://usuarios.lycos.es/xfce4/tarballs/rc2/separate/ \
		http://linux.imp.mx/xfce4/rc2/xfce4-rc2/src/
DISTNAME=	xfce-utils-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XFce 4 essential utilities and scripts

LIB_DEPENDS=	xfce4util.1:${PORTSDIR}/x11/libxfce4util \
		xfcegui4.1:${PORTSDIR}/x11-toolkits/libxfce4gui \
		xfce4mcs-manager.1:${PORTSDIR}/sysutils/xfce4-mcs-manager

USE_GNOME=	gtk20
#USE_REINPLACE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
