# New ports collection makefile for:	iriverter
# Date created:		2006-09-05
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	iriverter
PORTVERSION=	0.16
CATEGORIES=	multimedia java
MASTER_SITES=	SOURCEFORGE

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Cross-platform frontend to mencoder

BUILD_DEPENDS=	${JAVALIBDIR}/swt.jar:${PORTSDIR}/x11-toolkits/swt31 \
		${LOCALBASE}/lib/libswt-gnome-gtk-3139.so:${PORTSDIR}/x11-toolkits/swt31
RUN_DEPENDS=	${JAVALIBDIR}/swt.jar:${PORTSDIR}/x11-toolkits/swt31 \
		${LOCALBASE}/lib/libswt-gnome-gtk-3139.so:${PORTSDIR}/x11-toolkits/swt31 \
		mencoder:${PORTSDIR}/multimedia/mplayer

USE_JAVA=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-swt="${JAVALIBDIR}/swt.jar"

.include <bsd.port.mk>
