# New ports collection makefile for:    avidemux2
# Date created:         16 April 2003
# Whom:                 Anish Mistry
#                       with help from mean
# $FreeBSD$
#

PORTNAME=	avidemux2
PORTVERSION=	2.3.0
CATEGORIES=	multimedia
MASTER_SITES=	http://fixounet.free.fr/avidemux/ \
		${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	avidemux
DISTNAME=	avidemux_${PORTVERSION}

MAINTAINER=	amistry@am-productions.biz
COMMENT=	Simple GUI based video editor

PATCH_DEPENDS=	${ACLOCAL}:${PORTSDIR}/devel/automake19
BUILD_DEPENDS=	spidermonkey>=1.5_3:${PORTSDIR}/lang/spidermonkey
LIB_DEPENDS=	mp3lame:${PORTSDIR}/audio/lame \
		mad:${PORTSDIR}/audio/libmad \
		js:${PORTSDIR}/lang/spidermonkey \
		xml2:${PORTSDIR}/textproc/libxml2

USE_AUTOTOOLS=	automake:19:env autoconf:259:env libtool:15 aclocal:19:env
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gtk20
WANT_SDL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include \
		-I${LOCALBASE}/include/a52dec" \
		LIBFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}" \
		PTHREAD_LIBS=${PTHREAD_LIBS} \
		PTHREAD_CFLAGS=${PTHREAD_CFLAGS}
CONFIGURE_ARGS=	--disable-warnings \
		--with-jsapi-include=${LOCALBASE}/include
USE_GMAKE=	yes
DESKTOP_ENTRIES=	Avidemux "Simple video editor" "" "avidemux2" "" false
OPTIONS=	OPTIMIZED_CFLAGS "build with -O3 for lavcodec" off \
		FAAC "FAAC (mpeg4/aac encoder)" off \
		FAAD "FAAD (mpeg4/aac decoder)" off \
		X264 "H.264 encoding" off \
		A52 "A52 audio" off \
		XVID "Xvid video" off \
		SDL "SDL audio/video framework" off \
		VORBIS "OGG/Vorbis audio support" off

.include <bsd.port.pre.mk>

#.if ${HAVE_SDL:Msdl}!=""
#WITH_SDL=	yes
#.endif

.if exists(${LOCALBASE}/lib/libvorbis.so)
WITH_VORBIS=	yes
.endif

.if exists(${LOCALBASE}/lib/libx264.so)
WITH_X264=	yes
.endif

.if exists(${LOCALBASE}/lib/libfaac.so)
WITH_FAAC=	yes
.endif

.if exists(${LOCALBASE}/lib/libfaad.so)
WITH_FAAD=	yes
.endif

.if exists(${LOCALBASE}/lib/liba52.so)
WITH_A52=	yes
.endif

.if exists(${LOCALBASE}/lib/libxvidcore.so)
WITH_XVID=	yes
.endif

.if defined(WITH_XVID)
LIB_DEPENDS+=	xvidcore:${PORTSDIR}/multimedia/xvid
CONFIGURE_ARGS+=	--with-xvid-as-decoder
.endif

.if defined(WITH_A52)
LIB_DEPENDS+=	a52:${PORTSDIR}/audio/liba52
.endif

.if defined(WITH_SDL)
USE_SDL+=	sdl
.endif

.if defined(WITH_FAAC)
LIB_DEPENDS+=	faac:${PORTSDIR}/audio/faac
.endif

.if defined(WITH_FAAD)
LIB_DEPENDS+=	faad:${PORTSDIR}/audio/faad
.endif

.if defined(WITH_X264)
LIB_DEPENDS+=	x264:${PORTSDIR}/multimedia/x264
.endif

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
.endif

post-extract:
	@${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//' \
		${WRKSRC}/avidemux/ADM_mplex/ADM_mplexout.cpp

pre-build:
	@${FIND} ${WRKSRC} -type f -print0 | \
	${XARGS} -x -n 10 -0 ${TOUCH}

post-patch:
	@${TOUCH} ${WRKSRC}/*
	@${REINPLACE_CMD} 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure ${WRKSRC}/*/*/Makefile
	@${REINPLACE_CMD} 's|<malloc.h>|<stdlib.h>|g' ${WRKSRC}/avidemux/ADM_lavcodec/*.c
	@${REINPLACE_CMD} 's|<malloc.h>|<stdlib.h>|g' ${WRKSRC}/avidemux/ADM_lavcodec/*/*.c
	@${REINPLACE_CMD} 's|ADM_LOCALEDIR=$${datadir}/locale|ADM_LOCALEDIR=${PREFIX}/share/locale|' ${WRKSRC}/configure
	@${REINPLACE_CMD} "s|-O2|${CFLAGS}|" ${WRKSRC}/configure
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} "s|-O3|${CFLAGS}|" ${WRKSRC}/avidemux/ADM_lavcodec/Makefile.am
.endif

.include <bsd.port.post.mk>
