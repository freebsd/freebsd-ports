# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/net/libgweather/Makefile 18965 2013-12-20 11:02:42Z kwm $

PORTNAME=	libgweather
PORTVERSION=	3.6.2
CATEGORIES=	net gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to accessing online weather informations

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme
LIB_DEPENDS=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme

USES=		gettext gmake pathfix pkgconfig
USE_XZ=		yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomehier gnomeprefix intlhack gconf2 ltverhack gtk30
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GLIB_SCHEMAS=	org.gnome.GWeather.enums.xml \
		org.gnome.GWeather.gschema.xml

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so.*

.include <bsd.port.mk>
