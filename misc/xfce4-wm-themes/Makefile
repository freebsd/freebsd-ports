# New ports collection makefile for:	xfwm4-themes
# Date created:		7 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-wm-themes
PORTVERSION=	4.0.3
CATEGORIES=	misc xfce
MASTER_SITES=	http://www.xfce.org/archive/xfce-${PORTVERSION}/src/ \
                ftp://ftp.berlios.de/pub/xfce-goodies/${PORTVERSION}/xfce-${PORTVERSION}/src/ \
                http://hannelore.f1.fhtw-berlin.de/mirrors/xfce4/${PORTVERSION}/ \
                http://www.efd.lth.se/~c03bk/xfce4/mirror/tarballs/${PORTVERSION}/
DISTNAME=	xfwm4-themes-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 window decoration themes for xfwm4

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

NO_BUILD=	yes

.include <bsd.port.mk>
