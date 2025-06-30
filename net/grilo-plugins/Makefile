PORTNAME=	grilo-plugins
PORTVERSION=	0.3.16
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plugins for net/grilo
WWW=		https://wiki.gnome.org/Grilo

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgrilo-0.3.so:net/grilo \
		libavahi-gobject.so:net/avahi-app \
		libgdata.so:devel/libgdata \
		liboauth.so:net/liboauth \
		libgoa-1.0.so:net/gnome-online-accounts \
		libgom-1.0.so:databases/gom \
		libtotem-plparser.so:multimedia/totem-pl-parser \
		libsoup-3.0.so:devel/libsoup3 \
		libmediaart-2.0.so:multimedia/libmediaart \
		libgmime-2.6.so:mail/gmime26 \
		libjson-glib-1.0.so:devel/json-glib \
		libtinysparql-3.0.so:devel/tinysparql

USES=		gettext gperf gnome gstreamer libarchive meson pathfix pkgconfig sqlite tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	glib20 intlhack libxml2
USE_GSTREAMER=	chromaprint
MESON_ARGS=	-Denable-lua-factory=no

OPTIONS_SUB=			yes
OPTIONS_DEFINE=			DMAP

DMAP_DESC=			DMAP (DAAP, DPAP & DACP) support with libdmapsharing
DMAP_MESON_YES=			enable-dmap
DMAP_LIB_DEPENDS=		libdmapsharing-4.0.so:net/libdmapsharing

.include <bsd.port.mk>
