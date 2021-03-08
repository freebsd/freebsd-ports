# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tracker-miners
PORTVERSION=	2.3.5
PORTREVISION=	7
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Miners for tracker2

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

BUILD_DEPENDS=	valac:lang/vala
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
		pathfix pkgconfig python:3.4+,build sqlite tar:xz
USE_GNOME=	cairo intltool libgsf libxml2
INSTALLS_ICONS=	yes

MESON_ARGS=	-Dsystemd_user_services=no \
		-Dcharset_detenction=icu \
		-Dunicode_support=icu \
		-Dstemmer=no
#		-Dbattery_detection=hal

OPTIONS_SUB=	yes
OPTIONS_DEFINE=		GSTREAMER RSS
OPTIONS_DEFAULT=	GSTREAMER RSS

GSTREAMER_MESON_ON=	-Dgeneric_media_extractor=gstreamer
GSTREAMER_MESON_OFF=	-Dgeneric_media_extractor=none
GSTREAMER_USE=		gstreamer1=yes

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
