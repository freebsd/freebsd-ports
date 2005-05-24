# New ports collection makefile for:	gdl
# Date created:				24 July 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gdl
PORTVERSION=	0.5.0
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.5

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Components intended to be shared between GNOME development tools

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
