# New ports collection makefile for:	xffm-icons
# Date created:		7 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-fm-icons
PORTVERSION=	4.0.0
CATEGORIES=	x11-fm xfce
MASTER_SITES=	http://www.xfce.org/archive/xfce-${PORTVERSION}/src/ \
		http://linux.imp.mx/xfce4/xfce_${PORTVERSION}/src/
DISTNAME=	xffm-icons-${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 icon themes for the xffm file manager

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

NO_BUILD=	yes

.include <bsd.port.mk>
