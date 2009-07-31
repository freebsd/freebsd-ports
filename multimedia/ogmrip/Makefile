# New ports collection makefile for:	ogmrip
# Date created:				2004-11-19
# Whom:					Herve Quiroz <hq@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ogmrip
PORTVERSION=	0.12.3
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Application and libraries for encoding DVDs into DivX/OGM files

BUILD_DEPENDS=	mencoder:${PORTSDIR}/multimedia/mencoder \
		gsed:${PORTSDIR}/textproc/gsed
LIB_DEPENDS=	enca.5:${PORTSDIR}/converters/enca \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		dvdread.4:${PORTSDIR}/multimedia/libdvdread
RUN_DEPENDS=	lame:${PORTSDIR}/audio/lame \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		mencoder:${PORTSDIR}/multimedia/mencoder \
		ogmmerge:${PORTSDIR}/multimedia/ogmtools

OPTIONS=	GUI      "Build the GTK+ GUI"                           on  \
		HAL      "Enable Hardware Abstract Layer (HAL) support" off \
		ENCHANT  "Enable spell checking for text subtitles"     off \
		MATROSKA "Enable Matroska container support"            off \
		MP4      "Enable Mpeg-4 container support"              off \
		THEORA   "Enable Ogg Theora video codec support"        off \
		FAAC     "Enable Advance Audio Coding (AAC) support"    off \
		SRT      "Enable SRT text subtitles support"            off \
		DEBUG    "Enable debug"                                 off

USE_GNOME=	glib20 gnomehack libxml2
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		ac_cv_path_EJECT_PROG="/usr/sbin/cdcontrol"
USE_LDCONFIG=	yes

MAN1=		dvdcpy.1

.include <bsd.port.pre.mk>

.if defined(WITHOUT_GUI)
CONFIGURE_ARGS+=	--disable-gtk-support --disable-libnotify-support
PLIST_SUB+=		GUI_SUPPORT="@comment "
.else
CONFIGURE_ARGS+=	--enable-gtk-support --enable-libnotify-support
LIB_DEPENDS+=		notify.1:${PORTSDIR}/devel/libnotify
USE_GNOME+=		gconf2 intlhack libglade2
GCONF_SCHEMAS=		ogmrip.schemas
PLIST_SUB+=		GUI_SUPPORT=""
.endif

.if defined(WITH_HAL)
CONFIGURE_ARGS+=	--enable-hal-support
LIB_DEPENDS+=		hal:${PORTSDIR}/sysutils/hal
PLIST_SUB+=		HAL_SUPPORT=""
.else
CONFIGURE_ARGS+=	--disable-hal-support
PLIST_SUB+=		HAL_SUPPORT="@comment "
.endif

.if defined(WITH_ENCHANT)
CONFIGURE_ARGS+=	--enable-enchant-support
LIB_DEPENDS+=		enchant:${PORTSDIR}/textproc/enchant
PLIST_SUB+=		ENCHANT_SUPPORT=""
.else
CONFIGURE_ARGS+=	--disable-enchant-support
PLIST_SUB+=		ENCHANT_SUPPORT="@comment "
.endif

.if defined(WITH_MATROSKA)
CONFIGURE_ARGS+=	--enable-mkv-support
RUN_DEPENDS+=		mkvmerge:${PORTSDIR}/multimedia/mkvtoolnix
PLIST_SUB+=		MATROSKA_SUPPORT=""
.else
CONFIGURE_ARGS+=	--disable-mkv-support
PLIST_SUB+=		MATROSKA_SUPPORT="@comment "
.endif

.if defined(WITH_MP4)
CONFIGURE_ARGS+=	--enable-mp4-support
RUN_DEPENDS+=		mp4box:${PORTSDIR}/multimedia/gpac-mp4box
PLIST_SUB+=		MP4_SUPPORT=""
.else
CONFIGURE_ARGS+=	--disable-mp4-support
PLIST_SUB+=		MP4_SUPPORT="@comment "
.endif

.if defined(WITH_THEORA)
CONFIGURE_ARGS+=	--enable-theora-support
LIB_DEPENDS+=		theora:${PORTSDIR}/multimedia/libtheora
PLIST_SUB+=		THEORA_SUPPORT=""
.else
CONFIGURE_ARGS+=	--disable-theora-support
PLIST_SUB+=		THEORA_SUPPORT="@comment "
.endif

.if defined(WITH_FAAC)
CONFIGURE_ARGS+=	--enable-aac-support
RUN_DEPENDS+=		faac:${PORTSDIR}/audio/faac
PLIST_SUB+=		FAAC_SUPPORT=""
.else
CONFIGURE_ARGS+=	--disable-aac-support
PLIST_SUB+=		FAAC_SUPPORT="@comment "
.endif

.if defined(WITH_SRT)
CONFIGURE_ARGS+=	--enable-srt-support
RUN_DEPENDS+=		gocr:${PORTSDIR}/graphics/gocr
MAN1+=			subp2pgm.1 subptools.1
PLIST_SUB+=		SRT_SUPPORT=""
.else
CONFIGURE_ARGS+=	--disable-srt-support
PLIST_SUB+=		SRT_SUPPORT="@comment "
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-maintainer-mode --enable-devel-mode
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "This port requires a version of MEncoder compiled with XviD and/or"
	@${ECHO_MSG} "x264 support if you want to use these codecs."
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g ; \
		 s|^CPPFLAGS=|#CPPFLAGS=|g ; \
		 s|^LDFLAGS=|#LDFLAGS|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|^SUBDIRS|#SUBDIRS|g' ${WRKSRC}/docs/Makefile.in
	@${REINPLACE_CMD} -e \
		'/PROGRAM/s|MP4Box|mp4box|g' ${WRKSRC}/libogmrip/ogmrip-mp4.c

post-install:
	@${ECHO_CMD} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} ""

.include <bsd.port.post.mk>
