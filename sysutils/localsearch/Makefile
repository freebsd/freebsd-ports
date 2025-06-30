PORTNAME=	localsearch
PORTVERSION= 	3.8.2
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT= 	collection of data extractors for Tracker/Nepomuk
WWW= 		https://gnome.pages.gitlab.gnome.org/localsearch/

LICENSE= 	LGPL21 GPLv2+
LICENSE_COMB=	multi

BUILD_DEPENDS=	a2x:textproc/asciidoc
LIB_DEPENDS=	libexempi.so:textproc/exempi \
		libgexiv2.so:graphics/gexiv2 \
		libgudev-1.0.so:devel/libgudev \
		libcue.so:textproc/libcue \
		libexif.so:graphics/libexif \
		libgsf-1.so:devel/libgsf \
		libgxps.so:graphics/libgxps \
		libiptcdata.so:graphics/libiptcdata \
		libosinfo-1.0.so:devel/libosinfo \
		libpoppler-glib.so:graphics/poppler-glib \
		libtiff.so:graphics/tiff \
		libtinysparql-3.0.so.0:devel/tinysparql \
		libtotem-plparser.so:multimedia/totem-pl-parser \
		libupower-glib.so:sysutils/upower \
		libgif.so:graphics/giflib

USES=	tar:xz meson pkgconfig gstreamer gnome
USE_GSTREAMER= core good bad
USE_GNOME=	glib20

GLIB_SCHEMAS=	org.freedesktop.Tracker3.Extract.gschema.xml \
		org.freedesktop.Tracker3.FTS.gschema.xml \
		org.freedesktop.Tracker3.Miner.Files.gschema.xml \
		org.freedesktop.TrackerMiners3.enums.xml

LDFLAGS=	-L/usr/local/lib
MESON_ARGS=	-Dminer_rss=false \
		-Dfunctional_tests=false \
		-Dnetwork_manager=disabled \
		-Dsystemd_user_services=false \
		-Dlandlock=disabled \
		-Dfanotify=disabled


.include <bsd.port.mk>
