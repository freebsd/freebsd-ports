# New ports collection makefile for:	gtkbe
# Date Created:				6 July 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkbe
PORTVERSION= 	200007091019
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.themes.org/pub/themes/gtk/
DISTNAME=	GTK-Be-1.2.x-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

WRKSRC=		${WRKDIR}/GTKBeEngine

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

.include <bsd.port.mk>
