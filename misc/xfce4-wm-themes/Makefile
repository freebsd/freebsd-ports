# New ports collection makefile for:	xfwm4-themes
# Date created:		7 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-wm-themes
PORTVERSION=	4.0.0
CATEGORIES=	misc xfce
MASTER_SITES=	http://www.xfce.org/archive/xfce-${PORTVERSION}/src/ \
		http://linux.imp.mx/xfce4/xfce_${PORTVERSION}/src/
DISTNAME=	xfwm4-themes-${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 window decoration themes for xfwm4

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

NO_BUILD=	yes

.include <bsd.port.mk>
