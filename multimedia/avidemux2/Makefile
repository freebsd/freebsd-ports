# New ports collection makefile for:    avidemux2
# Date created:         16 April 2003
# Whom:                 Anish Mistry
#                       with help from mean
# $FreeBSD$
#

PORTNAME=	avidemux2
PORTVERSION=	2.1.2
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://fixounet.free.fr/avidemux/ \
		${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	avidemux
DISTNAME=	avidemux-${PORTVERSION}

MAINTAINER=	amistry@am-productions.biz
COMMENT=	Simple GUI based video editor

PATCH_DEPENDS=	${ACLOCAL}:${PORTSDIR}/devel/automake19
LIB_DEPENDS=	mp3lame.0:${PORTSDIR}/audio/lame \
		mad.2:${PORTSDIR}/audio/libmad \
		xml2.5:${PORTSDIR}/textproc/libxml2
BUILD_DEPENDS=	${LOCALBASE}/lib/libjs.so:${PORTSDIR}/lang/spidermonkey
RUN_DEPENDS=	${LOCALBASE}/lib/libjs.so:${PORTSDIR}/lang/spidermonkey

USE_AUTOTOOLS=	automake:19:env autoconf:259:env libtool:15 aclocal:19:env
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

.if exists(${LOCALBASE}/lib/libfaad.so.0)
WITH_FAAD=	yes
.endif

.if exists(${LOCALBASE}/lib/liba52.so.0)
WITH_A52=	yes
.endif

.if exists(${LOCALBASE}/lib/libxvidcore.so.4)
WITH_XVID=	yes
.endif

.if defined(WITH_XVID)
LIB_DEPENDS+=	xvidcore.4:${PORTSDIR}/multimedia/xvid
CONFIGURE_ARGS+=	--with-xvid-as-decoder
.endif

.if defined(WITH_A52)
LIB_DEPENDS+=	a52.0:${PORTSDIR}/audio/liba52
.endif

.if defined(WITH_SDL)
USE_SDL+=	sdl
.endif

.if defined(WITH_FAAC)
LIB_DEPENDS+=	faac.0:${PORTSDIR}/audio/faac
.endif

.if defined(WITH_FAAD)
LIB_DEPENDS+=	faad.0:${PORTSDIR}/audio/faad
.endif

.if defined(WITH_X264)
LIB_DEPENDS+=	x264.47:${PORTSDIR}/multimedia/x264
.endif

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
.endif

.if ${OSVERSION} < 500000
BROKEN=		does not compile
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
	@${REINPLACE_CMD} 's|<malloc.h>|<stdlib.h>|g' ${WRKSRC}/adm_lavcodec/*.c
	@${REINPLACE_CMD} 's|<malloc.h>|<stdlib.h>|g' ${WRKSRC}/adm_lavcodec/*/*.c
	@${REINPLACE_CMD} 's|ADM_LOCALEDIR=$${datadir}/locale|ADM_LOCALEDIR=${PREFIX}/share/locale|' ${WRKSRC}/configure
	@${REINPLACE_CMD} "s|-O2|${CFLAGS}|" ${WRKSRC}/configure
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} "s|-O3|${CFLAGS}|" ${WRKSRC}/adm_lavcodec/Makefile.am
.endif
	@${REINPLACE_CMD} 's|SDL/|SDL11/|' \
		${WRKSRC}/avidemux/ADM_audiodevice/ADM_deviceSDL.cpp \
		${WRKSRC}/avidemux/ADM_gui2/GUI_sdlDraw.cpp \
		${WRKSRC}/avidemux/main.cpp
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} 's|-falign-loops=16||' ${WRKSRC}/configure \
		${WRKSRC}/adm_lavcodec/Makefile.in \
		${WRKSRC}/adm_lavcodec/Makefile.in \
		${WRKSRC}/adm_lavcodec/libpostproc/Makefile.in \
		${WRKSRC}/adm_lavcodec/libpostproc/Makefile.am
	@${REINPLACE_CMD} 's|-msse||' ${WRKSRC}/configure \
		${WRKSRC}/adm_lavcodec/Makefile.in \
		${WRKSRC}/adm_lavcodec/Makefile.am \
		${WRKSRC}/adm_lavcodec/libpostproc/Makefile.in \
		${WRKSRC}/adm_lavcodec/libpostproc/Makefile.am
.endif

.include <bsd.port.post.mk>
