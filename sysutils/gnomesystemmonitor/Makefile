# New ports collection makefile for:	gnomesystemmonitor
# Date created:				09 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/gnomesystemmonitor/Makefile,v 1.51 2005/10/04 03:07:41 ahze Exp $
#

PORTNAME=	gnomesystemmonitor
PORTVERSION=	2.12.2
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-system-monitor/2.12
DISTNAME=	gnome-system-monitor-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 system monitor program

LIB_DEPENDS=	gtop-2.0.2:${PORTSDIR}/devel/libgtop2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
INSTALLS_OMF=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack libgnomeui libwnck
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lutil"

GCONF_SCHEMAS=	gnome-system-monitor.schemas

.include <bsd.port.mk>
