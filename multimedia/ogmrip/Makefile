# New ports collection makefile for:	ogmrip
# Date created:				2004-11-19
# Whom:					Herve Quiroz <hq@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ogmrip
PORTVERSION=	0.11.0
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Application and libraries for encoding DVDs into DivX/OGM files

BUILD_DEPENDS=	lame:${PORTSDIR}/audio/lame \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		mencoder:${PORTSDIR}/multimedia/mencoder \
		ogmmerge:${PORTSDIR}/multimedia/ogmtools \
		${LOCALBASE}/sbin/eject:${PORTSDIR}/sysutils/eject \
		gsed:${PORTSDIR}/textproc/gsed
LIB_DEPENDS=	enca.5:${PORTSDIR}/converters/enca \
		dvdread.5:${PORTSDIR}/multimedia/libdvdread \
		x264:${PORTSDIR}/multimedia/x264
RUN_DEPENDS=	lame:${PORTSDIR}/audio/lame \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		mencoder:${PORTSDIR}/multimedia/mencoder \
		ogmmerge:${PORTSDIR}/multimedia/ogmtools \
		${LOCALBASE}/sbin/eject:${PORTSDIR}/sysutils/eject

USE_GNOME=	glib20 libxml2 gnomehack
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes

MAN1=		dvdcpy.1

OPTIONS=	GUI		"Build the GTK+ GUI"				on  \
		HAL		"Enable Hardware Abstract Layer (HAL) support"	off \
		FAAC		"Enable Advance Audio Coding (AAC) support"	off \
		SRT		"Enable SRT text subtitles support"		off \
		ENCHANT		"Enable spell checking for text subtitles"	off \
		THEORA		"Enable Ogg Theora video codec support"		off \
		MATROSKA	"Enable Matroska container support"		off \
		DEBUG		"Enable debug"					off

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-maintainer-mode --enable-devel-mode
.endif

.if defined(WITHOUT_GUI)
CONFIGURE_ARGS+=	--disable-gtk-support
PLIST_SUB+=		GUI_SUPPORT="@comment "
.else
CONFIGURE_ARGS+=	--enable-gtk-support
PLIST_SUB+=		GUI_SUPPORT=""
USE_GNOME+=		libglade2 gconf2 intlhack
GCONF_SCHEMAS=		ogmrip.schemas
.endif

.if defined(WITH_HAL)
CONFIGURE_ARGS+=	--enable-hal-support
LIB_DEPENDS+=		hal:${PORTSDIR}/sysutils/hal
PLIST_SUB+=		HAL_SUPPORT=""
.else
CONFIGURE_ARGS+=	--disable-hal-support
PLIST_SUB+=		HAL_SUPPORT="@comment "
.endif

.if defined(WITH_MATROSKA)
CONFIGURE_ARGS+=	--enable-matroska-support
BUILD_DEPENDS+=		mkvmerge:${PORTSDIR}/multimedia/mkvtoolnix
RUN_DEPENDS+=		mkvmerge:${PORTSDIR}/multimedia/mkvtoolnix
PLIST_SUB+=		MATROSKA_SUPPORT=""
.else
CONFIGURE_ARGS+=	--disable-matroska-support
PLIST_SUB+=		MATROSKA_SUPPORT="@comment "
.endif

.if defined(WITH_FAAC)
CONFIGURE_ARGS+=	--enable-aac-support
BUILD_DEPENDS+=		faac:${PORTSDIR}/audio/faac
RUN_DEPENDS+=		faac:${PORTSDIR}/audio/faac
PLIST_SUB+=		FAAC_SUPPORT=""
.else
CONFIGURE_ARGS+=	--disable-aac-support
PLIST_SUB+=		FAAC_SUPPORT="@comment "
.endif

.if defined(WITH_SRT)
CONFIGURE_ARGS+=	--enable-srt-support
BUILD_DEPENDS+=		gocr:${PORTSDIR}/graphics/gocr
RUN_DEPENDS+=		gocr:${PORTSDIR}/graphics/gocr
PLIST_SUB+=		SRT_SUPPORT=""
.else
CONFIGURE_ARGS+=	--disable-srt-support
PLIST_SUB+=		SRT_SUPPORT="@comment "
.endif

.if defined(WITH_THEORA)
CONFIGURE_ARGS+=	--enable-theora-support
LIB_DEPENDS+=		theora:${PORTSDIR}/multimedia/libtheora
PLIST_SUB+=		THEORA_SUPPORT=""
.else
CONFIGURE_ARGS+=	--disable-theora-support
PLIST_SUB+=		THEORA_SUPPORT="@comment "
.endif

.if defined(WITH_ENCHANT)
CONFIGURE_ARGS+=	--enable-enchant-support
LIB_DEPENDS+=		enchant:${PORTSDIR}/textproc/enchant
PLIST_SUB+=		ENCHANT_SUPPORT=""
.else
CONFIGURE_ARGS+=	--disable-enchant-support
PLIST_SUB+=		ENCHANT_SUPPORT="@comment "
.endif

X264_SUPPORT!=		${LOCALBASE}/bin/mencoder -ovc help 2> /dev/null | \
				${GREP} -q '^ *x264 *- .*$$' && \
	  			${ECHO_CMD} "" || ${ECHO_CMD} "@comment "
PLIST_SUB+=		X264_SUPPORT="${X264_SUPPORT}"

LAVF_SUPPORT!=		${LOCALBASE}/bin/mencoder -of help 2> /dev/null | \
				${GREP} -q '^ *lavf *- .*$$' && \
	  			${ECHO_CMD} "" || ${ECHO_CMD} "@comment "
PLIST_SUB+=		LAVF_SUPPORT="${LAVF_SUPPORT}"

post-patch:
	@${REINPLACE_CMD} -e 's|-I/usr/local/include||g ; \
		 s|-L/usr/local/lib||g ; \
		 s|-L/usr/pkg/lib||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|^SUBDIRS|#SUBDIRS|g' ${WRKSRC}/docs/Makefile.in

pre-configure:
	@if ${LOCALBASE}/mencoder -ovc help 2> /dev/null | ${GREP} -q "^ *xvid *- .*" ; then \
	  ${ECHO_MSG} "" ; \
	  ${ECHO_MSG} "This port requires a version of MEncoder compiled with XviD support." ; \
	  ${ECHO_MSG} "" ; \
	  ${FALSE} ; \
	fi

post-install:
	@${ECHO_CMD} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} ""

.include <bsd.port.post.mk>
