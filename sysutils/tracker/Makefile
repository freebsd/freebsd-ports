# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/sysutils/tracker/Makefile 18905 2013-11-19 10:31:31Z gusi $

PORTNAME=	tracker
PORTVERSION=	0.14.4
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Object database, tag/metadata database, search tool and indexer

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib \
		libexif.so:${PORTSDIR}/graphics/libexif \
		libwv-1.2.so:${PORTSDIR}/textproc/wv \
		libgmime-2.6.so:${PORTSDIR}/mail/gmime26 \
		libexempi.so:${PORTSDIR}/textproc/exempi \
		libhal.so:${PORTSDIR}/sysutils/hal \
		libtotem-plparser.so:${PORTSDIR}/multimedia/totem-pl-parser \
		libraptor.so:${PORTSDIR}/textproc/raptor \
		libogg.so:${PORTSDIR}/audio/libogg \
		libiptcdata.so:${PORTSDIR}/graphics/libiptcdata \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		librest-0.7.so:${PORTSDIR}/devel/librest \
		libgif.so:${PORTSDIR}/graphics/giflib \
		libFLAC.so:${PORTSDIR}/audio/flac \
		libcue.so:${PORTSDIR}/textproc/libcue \
		libtag.so:${PORTSDIR}/audio/taglib
RUN_DEPENDS=	xdg-desktop-icon:${PORTSDIR}/devel/xdg-utils \
		o3totxt:${PORTSDIR}/converters/o3read \
		pdftotext:${PORTSDIR}/graphics/poppler-utils \
		w3m:${PORTSDIR}/www/w3m

PLIST_SUB=	TRACKER_VER="0.14"

TRACKER_VER=	0.14

USES=		gettext gmake pathfix pkgconfig
USE_SQLITE=	3
USE_XZ=		yes
USE_GNOME=	gnomeprefix gtk30 intltool ltverhack
USE_LDCONFIG=	yes
USE_GSTREAMER=	core
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -L${LOCALBASE}/lib/tracker
CONFIGURE_ARGS=	--enable-video-extractor=gstreamer \
		--with-session-bus-services-dir=${LOCALBASE}/share/dbus-1/services \
		--enable-libexif --enable-libvorbis \
		--enable-libiptcdata --enable-miner-fs \
		--disable-meegotouch  --disable-miner-flickr \
	 	--enable-taglib \
		--enable-tracker-preferences --enable-poppler \
		--enable-libgsf \
		--disable-libosinfo --enable-libgif \
		--enable-libjpeg --enable-libtiff \
		--enable-libvorbis --enable-libflac \
		--enable-libcue
GLIB_SCHEMAS=	org.freedesktop.Tracker.DB.gschema.xml \
		org.freedesktop.Tracker.Extract.gschema.xml \
		org.freedesktop.Tracker.FTS.gschema.xml \
		org.freedesktop.Tracker.Miner.Files.gschema.xml \
		org.freedesktop.Tracker.Store.gschema.xml \
		org.freedesktop.Tracker.Writeback.gschema.xml \
		org.freedesktop.Tracker.enums.xml \
		org.freedesktop.Tracker.gschema.xml

#  --enable-miner-evolution
#  --enable-miner-thunderbird
#  --enable-miner-firefox  enable Firefox email data miner [[default=auto]]
#  --enable-nautilus-extension
#		--enable-tracker-search-bar
#  --enable-qt             enable Qt support, (MP3 album art) [[default=auto]]
#  --enable-tracker-search-bar
#                          enable tracker-search-bar[[default=auto]]
#  --enable-tracker-needle enable tracker-needle [[default=auto]]
#                          enable the tracker preferences dialog
#                          [[default=auto]]
#  --enable-tracker-explorer
#                          enable tracker-explorer[[default=auto]]
#  --enable-libstreamanalyzer
#                          enable libstreamananalyzer [[default=no]]
#  --disable-libxml2       disable HTML/XML extractors [[default=yes]]
#  --enable-gdkpixbuf      enable GdkPixbuf support, (MP3 album art)
#                          [[default=auto]]
#  --enable-generic-media-extractor=ARG
#                          enables one of the (gstreamer, xine, external, auto)
#                          generic media extractor backends [[default=auto]]
#  --disable-unzip-ps-gz-files
#                          disable unzipping ps.gz files [[default=yes]]
#
#
#  --enable-playlist       enable playlist support [[default=auto]]
#  --enable-guarantee-metadata
#                          enable guaranteed existence of some metadata
#                          [[default=no]]
#
#

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|libpng|libpng15|' ${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtracker-*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtracker-*.so.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/tracker-0.14/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/tracker-0.14/*/*.so*

.include <bsd.port.post.mk>
