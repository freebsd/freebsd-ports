# Created by: Herve Quiroz <hq@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ogmrip
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Application and libraries for encoding DVDs into DivX/OGM files

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	mencoder:${PORTSDIR}/multimedia/mencoder \
		mplayer:${PORTSDIR}/multimedia/mplayer \
		gsed:${PORTSDIR}/textproc/gsed
LIB_DEPENDS=	libenca.so:${PORTSDIR}/converters/enca \
		libpng.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libdvdread.so:${PORTSDIR}/multimedia/libdvdread
RUN_DEPENDS=	lame:${PORTSDIR}/audio/lame \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		mencoder:${PORTSDIR}/multimedia/mencoder \
		mplayer:${PORTSDIR}/multimedia/mplayer \
		ogmmerge:${PORTSDIR}/multimedia/ogmtools

OPTIONS_DEFINE=	GTK2 ENCHANT MATROSKA MP4BOX NLS THEORA FAAC SRT DEBUG
OPTIONS_DEFAULT=GTK2 NLS
ENCHANT_DESC=	Enable spell checking for text subtitles
MATROSKA_DESC=	Enable Matroska container support
MP4BOX_DESC=	Enable Mpeg-4 container support
THEORA_DESC=	Enable Ogg Theora video codec support
SRT_DESC=	Enable SRT text subtitles support

USES=		desktop-file-utils gmake libtool pathfix pkgconfig
USE_GNOME=	glib20 intlhack libxml2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
CONFIGURE_ARGS+=	--enable-gtk-support --enable-dbus-support \
			--enable-libnotify-support
LIB_DEPENDS+=		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
			libnotify.so:${PORTSDIR}/devel/libnotify
USE_GNOME+=		gconf2 libglade2
GCONF_SCHEMAS=		ogmrip.schemas
PLIST_SUB+=		GTK2_SUPPORT=""
.else
CONFIGURE_ARGS+=	--disable-gtk-support --disable-dbus-support \
			--disable-libnotify-support
PLIST_SUB+=		GTK2_SUPPORT="@comment "
.endif

.if ${PORT_OPTIONS:MENCHANT}
CONFIGURE_ARGS+=	--enable-enchant-support
LIB_DEPENDS+=		libenchant.so:${PORTSDIR}/textproc/enchant
PLIST_SUB+=		ENCHANT_SUPPORT=""
.else
CONFIGURE_ARGS+=	--disable-enchant-support
PLIST_SUB+=		ENCHANT_SUPPORT="@comment "
.endif

.if ${PORT_OPTIONS:MMATROSKA}
CONFIGURE_ARGS+=	--enable-mkv-support
RUN_DEPENDS+=		mkvmerge:${PORTSDIR}/multimedia/mkvtoolnix
PLIST_SUB+=		MATROSKA_SUPPORT=""
.else
CONFIGURE_ARGS+=	--disable-mkv-support
PLIST_SUB+=		MATROSKA_SUPPORT="@comment "
.endif

.if ${PORT_OPTIONS:MMP4BOX}
CONFIGURE_ARGS+=	--enable-mp4-support
RUN_DEPENDS+=		mp4box:${PORTSDIR}/multimedia/gpac-mp4box
PLIST_SUB+=		MP4BOX_SUPPORT=""
.else
CONFIGURE_ARGS+=	--disable-mp4-support
PLIST_SUB+=		MP4BOX_SUPPORT="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=			gettext
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

.if ${PORT_OPTIONS:MTHEORA}
CONFIGURE_ARGS+=	--enable-theora-support
LIB_DEPENDS+=		libtheora.so:${PORTSDIR}/multimedia/libtheora
PLIST_SUB+=		THEORA_SUPPORT=""
.else
CONFIGURE_ARGS+=	--disable-theora-support
PLIST_SUB+=		THEORA_SUPPORT="@comment "
.endif

.if ${PORT_OPTIONS:MFAAC}
CONFIGURE_ARGS+=	--enable-aac-support
RUN_DEPENDS+=		faac:${PORTSDIR}/audio/faac
PLIST_SUB+=		FAAC_SUPPORT=""
.else
CONFIGURE_ARGS+=	--disable-aac-support
PLIST_SUB+=		FAAC_SUPPORT="@comment "
.endif

.if ${PORT_OPTIONS:MSRT}
CONFIGURE_ARGS+=	--enable-srt-support
RUN_DEPENDS+=		gocr:${PORTSDIR}/graphics/gocr
MAN1+=			subp2pgm.1 subptools.1
PLIST_SUB+=		SRT_SUPPORT=""
.else
CONFIGURE_ARGS+=	--disable-srt-support
PLIST_SUB+=		SRT_SUPPORT="@comment "
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-maintainer-mode --enable-devel-mode
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "This port requires a version of MEncoder compiled with XviD and/or"
	@${ECHO_MSG} "x264 support if you want to use these codecs."
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e '/local/s|^CFLAGS=|#CFLAGS=|g ; \
		 /local/s|^CPPFLAGS=|#CPPFLAGS=|g ; \
		 /local/s|^LDFLAGS=|#LDFLAGS=|g ; \
		 s|libpng zlib|libpng|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|^SUBDIRS|#SUBDIRS|g' ${WRKSRC}/docs/Makefile.in
	@${REINPLACE_CMD} -e \
		'/PROGRAM/s|MP4Box|mp4box|g' ${WRKSRC}/libogmrip/ogmrip-mp4.c

.include <bsd.port.mk>
