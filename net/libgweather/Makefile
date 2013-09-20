# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/net/libgweather/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	libgweather
PORTVERSION=	2.30.3
PORTREVISION=	2
CATEGORIES=	net gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to accessing online weather informations

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme
LIB_DEPENDS=	soup-2.4:${PORTSDIR}/devel/libsoup
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme

CONFLICTS=	libgweather-3.[0-9]*

USES=		gettext pathfix pkgconfig
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gconf2 ltverhack
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	gweather.schemas

NO_STAGE=	yes
.include <bsd.port.mk>
