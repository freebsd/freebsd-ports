PORTNAME=	tracker-miners
PORTVERSION=	2.3.5
PORTREVISION=	42
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Miners for tracker2
WWW=		https://wiki.gnome.org/Projects/Tracker

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

LIB_DEPENDS=	libicuuc.so:devel/icu \
		libupower-glib.so:sysutils/upower \
		libexempi.so:textproc/exempi \
		libcue.so:textproc/libcue \
		libiptcdata.so:graphics/libiptcdata \
		libFLAC.so:audio/flac \
		libtotem-plparser.so:multimedia/totem-pl-parser \
		libpoppler-glib.so:graphics/poppler-glib \
		libpng.so:graphics/png \
		libtag.so:audio/taglib \
		libtiff.so:graphics/tiff \
		libgif.so:graphics/giflib \
		libvorbisfile.so:audio/libvorbis \
		libgxps.so:graphics/libgxps \
		libexif.so:graphics/libexif \
		libgexiv2.so:graphics/gexiv2 \
		libtracker-miner-2.0.so:sysutils/tracker

PORTSCOUT=	limitw:1,even

USES=		gettext gnome jpeg localbase:ldflags meson \
		pathfix pkgconfig python:build sqlite tar:xz vala:build
USE_GNOME=	cairo intltool libgsf libxml2

MESON_ARGS=	-Dsystemd_user_services=no \
		-Diso=disabled \
		-Dcharset_detection=icu \
#		-Dbattery_detection=hal

OPTIONS_SUB=	yes
OPTIONS_DEFINE=		GSTREAMER RSS
OPTIONS_DEFAULT=	GSTREAMER RSS

GSTREAMER_USES=		gstreamer
GSTREAMER_MESON_ON=	-Dgeneric_media_extractor=gstreamer
GSTREAMER_MESON_OFF=	-Dgeneric_media_extractor=none

RSS_DESC=		Tracker RSS miner
RSS_MESON_TRUE=		miner_rss
RSS_LIB_DEPENDS=	libgrss.so:net/libgrss

PLIST_SUB=	LIBVER=0.2.0

GLIB_SCHEMAS=	org.freedesktop.Tracker.Extract.gschema.xml \
		org.freedesktop.Tracker.Miner.Files.gschema.xml \
		org.freedesktop.Tracker.Writeback.gschema.xml \
		org.freedesktop.TrackerMiners.enums.xml

#post-install:
#	${RM} -rf ${STAGEDIR}/${PREFIX}/lib/systemd

.include <bsd.port.mk>
