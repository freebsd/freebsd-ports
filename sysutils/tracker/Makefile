# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tracker
PORTVERSION=	1.6.1
PORTREVISION=	6
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Object database, tag/metadata database, search tool and indexer

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libgmime-2.6.so:mail/gmime26 \
		libhal.so:sysutils/hal \
		libraptor.so:textproc/raptor \
		libuuid.so:misc/e2fsprogs-libuuid \
		libicutu.so:devel/icu \
		libmediaart-2.0.so:multimedia/libmediaart \
		librest-0.7.so:devel/librest
RUN_DEPENDS=	xdg-desktop-icon:devel/xdg-utils \
		o3totxt:converters/o3read \
		pdftotext:graphics/poppler-utils \
		w3m:www/w3m

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake gnome libarchive libtool \
		pathfix pkgconfig sqlite tar:xz
USE_GNOME=	gtk30 intltool introspection:build libxslt:build
USE_LDCONFIG=	yes
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
CONFIGURE_ENV+=		enable_miner_evolution=no \
			DATADIRNAME=share
INSTALL_TARGET=	install-strip
GLIB_SCHEMAS=	org.freedesktop.Tracker.DB.gschema.xml \
		org.freedesktop.Tracker.Extract.gschema.xml \
		org.freedesktop.Tracker.FTS.gschema.xml \
		org.freedesktop.Tracker.Miner.Files.gschema.xml \
		org.freedesktop.Tracker.Needle.gschema.xml \
		org.freedesktop.Tracker.Store.gschema.xml \
		org.freedesktop.Tracker.Writeback.gschema.xml \
		org.freedesktop.Tracker.enums.xml \
		org.freedesktop.Tracker.gschema.xml

PLIST_SUB=	TRACKER_VER="1.0" LIBVER=601

OPTIONS_DEFINE=		AUDIO_MINERS DOCUMENT_MINERS GRAPHIC_MINERS \
			WEB_MINERS
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
WEB_MINERS_BUILD_DEPENDS=	firefox>=0:www/firefox \
				thunderbird>=0:mail/thunderbird
WEB_MINERS_RUN_DEPENDS=		firefox>=0:www/firefox \
				thunderbird>=0:mail/thunderbird

AUDIO_MINERS_CONFIGURE_ENABLE=	libvorbis libflac taglib mp3 libcue playlist
AUDIO_MINERS_LIB_DEPENDS=	libtotem-plparser.so:multimedia/totem-pl-parser \
				libFLAC.so:audio/flac \
				libvorbis.so:audio/libvorbis \
				libcue.so:textproc/libcue \
				libogg.so:audio/libogg \
				libtag.so:audio/taglib

DOCUMENT_MINERS_CONFIGURE_ENABLE=	libgxps poppler libxml2 libgsf \
				abiword dvi ps exempi text
DOCUMENT_MINERS_LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib \
				libgxps.so:graphics/libgxps \
				libgsf-1.so:devel/libgsf \
				libexempi.so:textproc/exempi \
				libwv.so:textproc/wv

GRAPHIC_MINERS_CONFIGURE_ENABLE=	libexif libgif libjpeg libtiff icon libpng
GRAPHIC_MINERS_LIB_DEPENDS=	libexif.so:graphics/libexif \
				libgif.so:graphics/giflib \
				libpng.so:graphics/png \
				libtiff.so:graphics/tiff

# cirular dependancy tracker -> nautilus -> tracker
CONFIGURE_ARGS=		--disable-nautilus-extension
#NAUTILUS_CONFIGURE_ENABLE=	nautilus-extension
#NAUTILUS_USE=		GNOME=nautilus3

.include <bsd.port.mk>
