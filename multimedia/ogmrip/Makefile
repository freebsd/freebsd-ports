# New ports collection makefile for:	ogmrip
# Date created:				2004-11-19
# Whom:					Herve Quiroz <hq@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ogmrip
DISTVERSION=	0.10.3
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Application and libraries for encoding DVDs into DivX/OGM files

BUILD_DEPENDS=	mencoder:${PORTSDIR}/multimedia/mplayer \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		ogmmerge:${PORTSDIR}/multimedia/ogmtools \
		lame:${PORTSDIR}/audio/lame \
		gsed:${PORTSDIR}/textproc/gsed
RUN_DEPENDS=	mencoder:${PORTSDIR}/multimedia/mplayer \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		ogmmerge:${PORTSDIR}/multimedia/ogmtools \
		lame:${PORTSDIR}/audio/lame
LIB_DEPENDS=	dvdread.5:${PORTSDIR}/multimedia/libdvdread \
		x264:${PORTSDIR}/multimedia/x264

USE_LDCONFIG=	yes
USE_GETTEXT=	yes
USE_GNOME=	glib20 libxml2 gnomehack
GNU_CONFIGURE=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
USE_GSED=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS=	--sharedstatedir=${PREFIX}/libdata
GMAKE_ENV+=	GMSGFMT=${localbase}/bin/msgfmt

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
