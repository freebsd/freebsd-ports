# New ports collection makefile for:	xffm-icons
# Date created:		7 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-fm-icons
PORTVERSION=	3.99.3
CATEGORIES=	x11-fm xfce
MASTER_SITES=	http://www.xfce.org/archive/xfce4-rc3/src/ \
		ftp://ftp.unix-ag.org/user/bmeurer/xfce4/rc3/separate/ \
		http://usuarios.lycos.es/xfce4/tarballs/rc3/separate/ \
		http://linux.imp.mx/xfce4/rc2/xfce4-rc3/src/
DISTNAME=	xffm-icons-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 icon themes for the xffm file manager

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

NO_BUILD=	yes

.include <bsd.port.mk>
