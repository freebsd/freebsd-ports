# New ports collection makefile for:	battstat_applet
# Date created:			17 July 2000
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=       battstat-applet
PORTVERSION=    2.0.4
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://spektr.eu.org/~jp/battstat/
DISTNAME=	battstat_applet-${PORTVERSION}

MAINTAINER=	jim@FreeBSD.org

LIB_DEPENDS=	panel_applet.4:${PORTSDIR}/x11/gnomecore

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_LIBTOOL=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

.include <bsd.port.mk>
