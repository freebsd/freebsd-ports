# New ports collection makefile for:    libxine
# Date created:         14 Oct 2000
# Whom:                 alex
#
# $FreeBSD$
#

PORTNAME=	xine
PORTVERSION=	0.9.2
CATEGORIES=	graphics
MASTER_SITES=	http://xine.sourceforge.net/files/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	lib
DISTFILES=	${PORTNAME}-lib-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nobutaka@nobutaka.com

BUILD_DEPENDS=	${LOCALBASE}/lib/libavcodec.a:${PORTSDIR}/graphics/ffmpeg
LIB_DEPENDS=	a52.0:${PORTSDIR}/audio/liba52 \
		aa.1:${PORTSDIR}/graphics/aalib

WRKSRC=		${WRKDIR}/${PORTNAME}-lib-${PORTVERSION}
USE_AUTOMAKE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_IMLIB=	yes
USE_ESOUND=	yes
CONFIGURE_ARGS=	--with-w32-path=${LOCALBASE}/lib/win32
INSTALLS_SHLIB=	yes

MAN1=		xine-config.1
MAN3=		ao_driver_t.3 ao_functions_t.3 autoplay_group.3 \
		audio_cap.3 audio_group.3 audio_prop.3 \
		browse_group.3 build_info.3 cfg_data_t.3 config_group.3 \
		config_values_s.3 config_values_t.3 demux_strategy.3 \
		event_group.3 loadplugins_group.3 mrl_t.3 mrl_types.3 \
		status_group.3 ui_callbacks.3 version_group.3 video_cap.3 \
		video_group.3 video_prop.3 video_ratio.3 visual_types.3 \
		vo_driver_s.3 vo_driver_t.3 vo_frame_t.3 vo_overlay_t.3 \
		xine-lib.3 xine.h.3 xine_api.3 xine_init.3 xine_management.3 \
		xine_t.3 xine_version.3

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} >= 4
PLIST_SUB=	HAVE_LIBXV=""
.else
PLIST_SUB=	HAVE_LIBXV="@comment "
.endif

.if exists(${LOCALBASE}/bin/artsc-config)
PLIST_SUB+=	HAVE_ARTS=""
.else
PLIST_SUB+=	HAVE_ARTS="@comment "
.endif

.if exists(${LOCALBASE}/include/vorbis/codec.h)
LIB_DEPENDS+=	vorbis.0:${PORTSDIR}/audio/libvorbis

PLIST_SUB+=	HAVE_VORBIS=""
.else
PLIST_SUB+=	HAVE_VORBIS="@comment "
.endif

.if exists(${LOCALBASE}/include/ogg/ogg.h)
LIB_DEPENDS+=	ogg.2:${PORTSDIR}/audio/libogg

PLIST_SUB+=	HAVE_OGG=""
.else
PLIST_SUB+=	HAVE_OGG="@comment "
.endif

.if defined(WITH_CSS)
# http://members.home.nl/mphm.janssen/linuxvideo/linuxvideo.html
MASTER_SITES+=	http://members.home.nl/mphm.janssen/files/
DISTFILES+=	${PLUGIN_CSS}${EXTRACT_SUFX}

LIB_DEPENDS+=	dvdcss.0:${PORTSDIR}/graphics/libdvdcss

PLUGIN_CSS=	dvd-plugin-${PLUGIN_CSS_VERSION}
PLUGIN_CSS_VERSION=	0.4
.endif

pre-everything::
.if !defined(WITH_CSS)
	@${ECHO_MSG} "====>"
	@${ECHO_MSG} "====> To enable css support, define WITH_CSS"
	@${ECHO_MSG} "====>"
.endif

post-patch:
.if defined(WITH_CSS)
	@${PERL} -pi.orig -e 's/(xineplug_inp_dvd_la_LDFLAGS = -avoid-version -module)/\1 -ldvdcss/' \
		${WRKSRC}/src/input/Makefile.am
	@${CP} -f ${WRKDIR}/${PLUGIN_CSS}/*.[ch] ${WRKSRC}/src/input
.endif

.include <bsd.port.post.mk>
