# New ports collection makefile for:	libgnomecups
# Date created:				14 Jul 2003
# Whom:					Glenn Johnson <glennpj@charter.net>
#
# $FreeBSD$

PORTNAME=	libgnomecups
PORTVERSION=	0.1.5
PORTREVISION=	1
CATEGORIES=	print gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.1
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Support library for gnome cups admistration

LIB_DEPENDS=	cups.2:${PORTSDIR}/print/cups-base

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack glib20
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=  CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
