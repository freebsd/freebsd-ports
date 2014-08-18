# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/sysutils/tracker/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME=	tracker
PORTVERSION=	1.1.2
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
		libmediaart-1.0.so:${PORTSDIR}/multimedia/libmediaart \
		librest-0.7.so:${PORTSDIR}/devel/librest
RUN_DEPENDS=	xdg-desktop-icon:${PORTSDIR}/devel/xdg-utils \
		o3totxt:${PORTSDIR}/converters/o3read \
		pdftotext:${PORTSDIR}/graphics/poppler-utils \
		w3m:${PORTSDIR}/www/w3m

PLIST_SUB=	TRACKER_VER="1.0"

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix gtk30 intltool introspection:build
USE_LDCONFIG=	yes
USE_SQLITE=	3
USE_GSTREAMER1=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -L${LOCALBASE}/lib/tracker
CONFIGURE_ARGS=	--enable-video-extractor=gstreamer \
		--with-session-bus-services-dir=${LOCALBASE}/share/dbus-1/services \
		--disable-libiptcdata --enable-miner-fs \
		--disable-meegotouch  --disable-miner-flickr \
		--enable-icu-charset-detection \
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

OPTIONS_DEFINE=		AUDIO_MINERS DOCUMENT_MINERS GRAPHIC_MINERS WEB_MINERS
OPTIONS_DEFAULT=	AUDIO_MINERS DOCUMENT_MINERS GRAPHIC_MINER
WEB_MINERS_DESC=	Support for Firefox, Thunderbird and Evolution
AUDIO_MINERS_DESC=	Support for audio files
DOCUMENT_MINERS_DESC=	Support for some sort of documents (pdf, ps, xps, office)
GRAPHIC_MINERS_DESC=	Support for some graphic formats (gif, png, tiff)

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MWEB_MINERS}
CONFIGURE_ARGS+=	--enable-miner-firefox \
			--enable-miner-thunderbird
BUILD_DEPENDS+=	firefox>=0:${PORTSDIR}/www/firefox \
		thunderbird>=0:${PORTSDIR}/mail/thunderbird
RUN_DEPENDS+=	firefox>=0:${PORTSDIR}/www/firefox \
		thunderbird>=0:${PORTSDIR}/mail/thunderbird
PLIST_SUB+=	WEB_MINERS=""
.else
CONFIGURE_ARGS+=	--disable-miner-evolution --disable-miner-firefox \
			--disable-miner-thunderbird
PLIST_SUB+=	WEB_MINERS="@comment "
.endif

.if ${PORT_OPTIONS:MAUDIO_MINERS}
LIB_DEPENDS+=	libtotem-plparser.so:${PORTSDIR}/multimedia/totem-pl-parser \
		libFLAC.so:${PORTSDIR}/audio/flac \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libcue.so:${PORTSDIR}/textproc/libcue \
		libogg.so:${PORTSDIR}/audio/libogg \
		libtag.so:${PORTSDIR}/audio/taglib
CONFIGURE_ARGS+=	--enable-libvorbis --enable-libflac \
			--enable-taglib --enable-mp3 \
			--enable-libcue --enable-playlist
PLIST_SUB+=	AUDIO_MINERS=""
.else
CONFIGURE_ARGS+=	--disable-libvorbis --disable-libflac \
			--disable-taglib --disable-mp3 \
			--disable-libcue --disable-playlist
PLIST_SUB+=	AUDIO_MINERS="@comment "
.endif

.if ${PORT_OPTIONS:MDOCUMENT_MINERS}
LIB_DEPENDS+=	libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib \
		libgxps.so:${PORTSDIR}/graphics/libgxps \
		libgsf-1.so:${PORTSDIR}/devel/libgsf \
		libexempi.so:${PORTSDIR}/textproc/exempi \
		libwv.so:${PORTSDIR}/textproc/wv
CONFIGURE_ARGS+=	--enable-libgxps --enable-poppler \
			--enable-libxml2 --enable-exif \
			--enable-libgsf --enable-abiword \
			--enable-dvi --enable-ps \
			--enable-exempi --enable-text
PLIST_SUB+=	DOCUMENT_MINERS=""
.else
CONFIGURE_ARGS+=	--disable-libgxps --disable-poppler \
			--disable-libxml2 --disable-exif \
			--disable-libgsf --disable-abiword \
			--disable-dvi --disable-ps \
			--disable-exempi --disable-text
PLIST_SUB+=	DOCUMENT_MINERS="@comment "
.endif

.if ${PORT_OPTIONS:MGRAPHIC_MINERS}
LIB_DEPENDS+=	libexif.so:${PORTSDIR}/graphics/libexif \
		libgif.so:${PORTSDIR}/graphics/giflib \
		libpng15.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff
CONFIGURE_ARGS+=	--enable-libgif \
			--enable-libjpeg \
			--enable-libtiff \
			--enable-icon \
			--enable-libpng15
PLIST_SUB+=	GRAPHIC_MINERS=""
.else
CONFIGURE_ARGS+=	--disable-libgif \
			--disable-libjpeg \
			--disable-libtiff \
			--disable-icon \
			--disable-libpng15
PLIST_SUB+=	GRAPHIC_MINERS="@comment "
.endif

.include <bsd.port.post.mk>
