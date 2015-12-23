# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tracker
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Object database, tag/metadata database, search tool and indexer

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libgmime-2.6.so:${PORTSDIR}/mail/gmime26 \
		libhal.so:${PORTSDIR}/sysutils/hal \
		libraptor.so:${PORTSDIR}/textproc/raptor \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libicutu.so:${PORTSDIR}/devel/icu \
		libmediaart-2.0.so:${PORTSDIR}/multimedia/libmediaart \
		librest-0.7.so:${PORTSDIR}/devel/librest
RUN_DEPENDS=	xdg-desktop-icon:${PORTSDIR}/devel/xdg-utils \
		o3totxt:${PORTSDIR}/converters/o3read \
		pdftotext:${PORTSDIR}/graphics/poppler-utils \
		w3m:${PORTSDIR}/www/w3m

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	gtk30 intltool introspection:build libxslt:build
USE_LDCONFIG=	yes
USE_SQLITE=	3
USE_GSTREAMER1=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-session-bus-services-dir=${LOCALBASE}/share/dbus-1/services \
		--disable-libiptcdata --enable-miner-fs \
		--disable-meegotouch \
		--enable-icu-charset-detection \
		--disable-network-manager \
		--disable-enca \
		--enable-tracker-preferences \
		--disable-libosinfo \
		--enable-generic-media-extractor=gstreamer
# disable evolution miner until tracker fixes the dep
CONFIGURE_ARGS+=	--disable-miner-evolution
INSTALL_TARGET=	install-strip
GLIB_SCHEMAS=	org.freedesktop.Tracker.DB.gschema.xml \
		org.freedesktop.Tracker.Extract.gschema.xml \
		org.freedesktop.Tracker.FTS.gschema.xml \
		org.freedesktop.Tracker.Miner.Files.gschema.xml \
		org.freedesktop.Tracker.Store.gschema.xml \
		org.freedesktop.Tracker.Writeback.gschema.xml \
		org.freedesktop.Tracker.enums.xml \
		org.freedesktop.Tracker.gschema.xml

PLIST_SUB=	TRACKER_VER="1.0" LIBVER=400

OPTIONS_DEFINE=		AUDIO_MINERS DOCUMENT_MINERS GRAPHIC_MINERS \
			NAUTILUS WEB_MINERS
OPTIONS_DEFAULT=	AUDIO_MINERS DOCUMENT_MINERS GRAPHIC_MINERS
OPTIONS_SUB=yes
WEB_MINERS_DESC=	Support for Firefox, Thunderbird
# and Evolution
AUDIO_MINERS_DESC=	Support for audio formats
DOCUMENT_MINERS_DESC=	Support for some sort of documents (pdf, ps, xps, office)
GRAPHIC_MINERS_DESC=	Support for some graphic formats (gif, png, tiff)
NAUTILUS_DESC=		Support for nautilus tagging

WEB_MINERS_CONFIGURE_ENABLE=	miner-firefox miner-thunderbird
# miner-evolution
WEB_MINERS_BUILD_DEPENDS=	firefox>=0:${PORTSDIR}/www/firefox \
				thunderbird>=0:${PORTSDIR}/mail/thunderbird
WEB_MINERS_RUN_DEPENDS=		firefox>=0:${PORTSDIR}/www/firefox \
				thunderbird>=0:${PORTSDIR}/mail/thunderbird

AUDIO_MINERS_CONFIGURE_ENABLE=	libvorbis libflac taglib mp3 libcue playlist
AUDIO_MINERS_LIB_DEPENDS=	libtotem-plparser.so:${PORTSDIR}/multimedia/totem-pl-parser \
				libFLAC.so:${PORTSDIR}/audio/flac \
				libvorbis.so:${PORTSDIR}/audio/libvorbis \
				libcue.so:${PORTSDIR}/textproc/libcue \
				libogg.so:${PORTSDIR}/audio/libogg \
				libtag.so:${PORTSDIR}/audio/taglib

DOCUMENT_MINERS_CONFIGURE_ENABLE=	libgxps poppler libxml2 libgsf \
				abiword dvi ps exempi text
DOCUMENT_MINERS_LIB_DEPENDS=	libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib \
				libgxps.so:${PORTSDIR}/graphics/libgxps \
				libgsf-1.so:${PORTSDIR}/devel/libgsf \
				libexempi.so:${PORTSDIR}/textproc/exempi \
				libwv.so:${PORTSDIR}/textproc/wv

GRAPHIC_MINERS_CONFIGURE_ENABLE=	libexif libgif libjpeg libtiff icon libpng
GRAPHIC_MINERS_LIB_DEPENDS=	libexif.so:${PORTSDIR}/graphics/libexif \
				libgif.so:${PORTSDIR}/graphics/giflib \
				libpng.so:${PORTSDIR}/graphics/png \
				libtiff.so:${PORTSDIR}/graphics/tiff

NAUTILUS_CONFIGURE_ENABLE=	nautilus-extension
NAUTILUS_USE=		GNOME=nautilus3

.include <bsd.port.mk>
