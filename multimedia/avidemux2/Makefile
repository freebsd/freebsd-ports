# New ports collection makefile for:    avidemux2
# Date created:         16 April 2003
# Whom:                 Anish Mistry
#                       with help from mean
# $FreeBSD$
#

PORTNAME=	avidemux2
PORTVERSION=	2.0.20
CATEGORIES=	multimedia
MASTER_SITES=	http://fixounet.free.fr/avidemux/
DISTNAME=	avidemux-2.0.20

MAINTAINER=	amistry@am-productions.biz
COMMENT=	Simple GUI based video editor

LIB_DEPENDS=	mp3lame.0:${PORTSDIR}/audio/lame \
		mad.2:${PORTSDIR}/audio/libmad \
		xml2.5:${PORTSDIR}/textproc/libxml2
BUILD_DEPENDS=	\
	${X11BASE}/include/X11/extensions/Xvlib.h:${PORTSDIR}/graphics/xv

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
USE_GNOME=	gnomeprefix gnomehack gtk20
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

.if exists(${LOCALBASE}/bin/mpeg2enc)
WITH_MPEGENC=	yes
.endif

.if exists(${LOCALBASE}/lib/liba52.so.0)
WITH_A52=	yes
.endif

.if exists(${LOCALBASE}/lib/libxvidcore.so.2)
WITH_XVID=	yes
.endif

.if defined(WITH_MPEGENC)
RUN_DEPENDS+=	mpeg2enc:${PORTSDIR}/multimedia/mjpegtools
.endif

.if defined(WITH_XVID)
LIB_DEPENDS+=	xvidcore.2:${PORTSDIR}/multimedia/xvid
CONFIGURE_ARGS+=	--with-xvid-as-decoder
.endif

.if ${MACHINE_ARCH} != "i386"
CONFIGURE_ARGS+=	--disable-mmx
.endif

.if defined(WITH_A52)
LIB_DEPENDS+=	a52.0:${PORTSDIR}/audio/liba52
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

post-patch:
	@${TOUCH} ${WRKSRC}/*
	@${REINPLACE_CMD} 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure ${WRKSRC}/*/*/Makefile
	@${REINPLACE_CMD} 's|<malloc.h>|<stdlib.h>|g' ${WRKSRC}/adm_lavcodec/*.c
	@${REINPLACE_CMD} 's|ADM_LOCALEDIR=$${datadir}/locale|ADM_LOCALEDIR=${PREFIX}/share/locale|' ${WRKSRC}/configure
.if ${OSVERSION} >= 500000
	@${ECHO_MSG} "Remove this ugly hack!"
	@${REINPLACE_CMD} 's|#define EMULATE_FAST_INT 1||g' ${WRKSRC}/configure
.endif

.include <bsd.port.post.mk>
