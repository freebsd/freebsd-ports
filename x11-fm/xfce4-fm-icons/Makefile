# New ports collection makefile for:	xffm-icons
# Date created:		7 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-fm-icons
PORTVERSION=	4.0.5
CATEGORIES=	x11-fm xfce
MASTER_SITES=	ftp://ftp.berlios.de/pub/xfce-goodies/${PORTVERSION}/ \
		http://hannelore.f1.fhtw-berlin.de/mirrors/xfce4/xfce-${PORTVERSION}/src/
DISTNAME=	xffm-icons-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 icon themes for the xffm file manager

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

NO_BUILD=	yes

.include <bsd.port.mk>
