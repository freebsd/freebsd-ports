# New ports collection makefile for:	libwnck
# Date created:				12 April 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/libwnck/Makefile,v 1.70 2006/04/13 07:52:43 bland Exp $
#

PORTNAME=	libwnck
PORTVERSION=	2.14.1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library used for writing pagers and taskslists

LIB_DEPENDS=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gtk20 ltverhack
USE_BISON=	yes
INSTALLS_SHLIB=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
