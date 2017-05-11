# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	geoclue
PORTVERSION=	2.4.3
CATEGORIES=	net devel gnome
MASTER_SITES=	http://www.freedesktop.org/software/geoclue/releases/${PORTVERSION:R}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	D-Bus service that provides location information

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libsoup-2.4.so:devel/libsoup

USES=		gettext gmake gnome libtool localbase pathfix \
		pkgconfig tar:xz
USE_GNOME=	glib20 intlhack introspection:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-3g-source \
		--disable-cdma-source \
		--disable-nmea-source \
		--disable-modem-gps-source
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
