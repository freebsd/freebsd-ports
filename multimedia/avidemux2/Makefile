# New ports collection makefile for:    avidemux2
# Date created:         16 April 2003
# Whom:                 Anish Mistry
#                       with help from mean
# $FreeBSD$
#

PORTNAME=	avidemux2
PORTVERSION=	2.0.38
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://fixounet.free.fr/avidemux/ \
		http://download.berlios.de/avidemux/
DISTNAME=	avidemux-${PORTVERSION}rc1

MAINTAINER=	amistry@am-productions.biz
COMMENT=	Simple GUI based video editor

PATCH_DEPENDS=	${ACLOCAL}:${PORTSDIR}/devel/automake${WANT_AUTOMAKE_VER}
LIB_DEPENDS=	mp3lame.0:${PORTSDIR}/audio/lame \
		mad.2:${PORTSDIR}/audio/libmad \
		xml2.5:${PORTSDIR}/textproc/libxml2

WANT_AUTOCONF_VER=259
WANT_AUTOCONF_RUN=yes
WANT_AUTOMAKE_VER=19
WANT_AUTOMAKE_RUN=yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
USE_GNOME=	gnomeprefix gnomehack gtk20
WANT_SDL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include \
		-I${LOCALBASE}/include/ffmpeg \
		-I${LOCALBASE}/include/a52dec" \
		LIBFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		PTHREAD_LIBS=${PTHREAD_LIBS} \
		PTHREAD_CFLAGS=${PTHREAD_CFLAGS}
CONFIGURE_ARGS=	--disable-warnings
USE_GMAKE=	yes
OPTIONS=	OPTIMIZED_CFLAGS "build with -O3 for lavcodec" off \
		FAAC "FAAC (mpeg4/aac encoder)" off \
		FAAD "FAAD (mpeg4/aac decoder)" off \
		MPEGENC "MPEG/MJPEG video" off \
		A52 "A52 audio" off \
		XVID "Xvid video" off \
		SDL "SDL audio/video framework" off

.include <bsd.port.pre.mk>

#.if ${HAVE_SDL:Msdl}!=""
#WITH_SDL=	yes
#.endif

.if exists(${LOCALBASE}/lib/libfaac.so)
WITH_FAAC=	yes
.endif

.if exists(${LOCALBASE}/lib/libfaad.so.0)
WITH_FAAD=	yes
.endif

.if exists(${LOCALBASE}/bin/mpeg2enc)
WITH_MPEGENC=	yes
.endif

.if exists(${LOCALBASE}/lib/liba52.so.0)
WITH_A52=	yes
.endif

.if exists(${LOCALBASE}/lib/libxvidcore.so.4)
WITH_XVID=	yes
.endif

.if defined(WITH_MPEGENC)
RUN_DEPENDS+=	mpeg2enc:${PORTSDIR}/multimedia/mjpegtools
.endif

.if defined(WITH_XVID)
LIB_DEPENDS+=	xvidcore.4:${PORTSDIR}/multimedia/xvid
CONFIGURE_ARGS+=	--with-xvid-as-decoder
.endif

.if ${ARCH} != "i386"
CONFIGURE_ARGS+=	--disable-mmx
.else
BUILD_DEPENDS+=		nasm:${PORTSDIR}/devel/nasm
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

post-extract:
	@${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//' \
		${WRKSRC}/avidemux/ADM_mplex/ADM_mplexout.cpp

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
#	 ACLOCAL hack see PR ports/41945
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOMAKE_ENV} ${ACLOCAL} \
		--acdir=${ACLOCAL_DIR})
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
