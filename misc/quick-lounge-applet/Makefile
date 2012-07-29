# New ports collection makefile for:	quick-lounge-applet
# Date created:				01 March 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/misc/quick-lounge-applet/Makefile,v 1.15 2010/11/16 10:06:22 kwm Exp $
#

PORTNAME=	quick-lounge-applet
PORTVERSION=	2.14.1
PORTREVISION=	1
CATEGORIES=	misc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Applet to originize your preferred applications on the GNOME Panel

USE_BZIP2=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomepanel
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	quick-lounge.schemas

.include <bsd.port.mk>
