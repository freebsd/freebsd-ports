# New ports collection makefile for:    avidemux2
# Date created:         16 April 2003
# Whom:                 Anish Mistry
#                       with help from mean
# $FreeBSD$
#

PORTNAME=	avidemux2
PORTVERSION=	2.0.26
CATEGORIES=	multimedia
MASTER_SITES=	http://fixounet.free.fr/avidemux/
DISTNAME=	avidemux-${PORTVERSION}

MAINTAINER=	amistry@am-productions.biz
COMMENT=	Simple GUI based video editor

LIB_DEPENDS=	mp3lame.0:${PORTSDIR}/audio/lame \
		mad.2:${PORTSDIR}/audio/libmad \
		xml2.5:${PORTSDIR}/textproc/libxml2
BUILD_DEPENDS=	\
	${X11BASE}/include/X11/extensions/Xvlib.h:${PORTSDIR}/graphics/xv

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
USE_GNOME=	gnomeprefix gnomehack gtk20
WANT_SDL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include \
		-I${LOCALBASE}/include/ffmpeg \
		-I${LOCALBASE}/include/a52dec" \
		LIBFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		PTHREAD_LIBS=${PTHREAD_LIBS} \
		PTHREAD_CFLAGS=${PTHREAD_CFLAGS}
CONFIGURE_ARGS=	--disable-warnings
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

#.if ${HAVE_SDL:Msdl}!=""
#WITH_SDL=	yes
#.endif

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

.if defined(WITH_FAAD)
LIB_DEPENDS+=	faad.0:${PORTSDIR}/audio/faad
.endif

pre-everything::
.if !defined(WITH_MPEGENC)
	@${ECHO_MSG} "To enable mpeg support define WITH_MPEGENC."
.endif

.if !defined(WITH_XVID)
	@${ECHO_MSG} "To enable xvid as the decoder define WITH_XVID."
.endif

.if !defined(WITH_A52)
	@${ECHO_MSG} "To enable A/52 support define WITH_A52."
.endif

.if !defined(WITH_SDL)
	@${ECHO_MSG} "To enable SDL support define WITH_SDL."
.endif

.if !defined(WITH_FAAD)
	@${ECHO_MSG} "To enable FAAD (mpeg4/aac) support define WITH_FAAD."
.endif

post-patch:
	@${TOUCH} ${WRKSRC}/*
	@${REINPLACE_CMD} 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure ${WRKSRC}/*/*/Makefile
	@${REINPLACE_CMD} 's|<malloc.h>|<stdlib.h>|g' ${WRKSRC}/adm_lavcodec/*.c
	@${REINPLACE_CMD} 's|<malloc.h>|<stdlib.h>|g' ${WRKSRC}/adm_lavcodec/*/*.c
	@${REINPLACE_CMD} 's|ADM_LOCALEDIR=$${datadir}/locale|ADM_LOCALEDIR=${PREFIX}/share/locale|' ${WRKSRC}/configure
	@${REINPLACE_CMD} "s|-O2|${CFLAGS}|" ${WRKSRC}/adm_lavcodec/Makefile
	@${REINPLACE_CMD} "s|-O2||" ${WRKSRC}/configure
	@${REINPLACE_CMD} 's|SDL/|SDL11/|' \
		${WRKSRC}/avidemux/ADM_audiodevice/ADM_deviceSDL.cpp \
		${WRKSRC}/avidemux/ADM_gui2/GUI_sdlDraw.cpp \
		${WRKSRC}/avidemux/main.cpp

.include <bsd.port.post.mk>
