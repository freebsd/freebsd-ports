# New ports collection makefile for:	quick-lounge-applet
# Date created:				01 March 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quick-lounge-applet
PORTVERSION=	2.1.2
CATEGORIES=	misc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.1
DIST_SUBDIR=	gnome2

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Applet to orginize your preferred applications on the GNOME Panel

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomepanel
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
