# New ports collection makefile for:    avidemux
# Date created:         15 August 2002
# Whom:                 Anish Mistry
#                       with help from mean
# $FreeBSD$
#

PORTNAME=	avidemux
PORTVERSION=	0.9.0.110
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://fixounet.free.fr/avidemux/
DISTNAME=	avidemux-0.9
EXTRACT_SUFX=	.tgz

MAINTAINER=	amistry@am-productions.biz
COMMENT=	Simple GUI-based video editor

LIB_DEPENDS=	mp3lame.0:${PORTSDIR}/audio/lame \
		mad.2:${PORTSDIR}/audio/mad \
		freetype.9:${PORTSDIR}/print/freetype2
BUILD_DEPENDS=	\
	${X11BASE}/include/X11/extensions/Xvlib.h:${PORTSDIR}/graphics/xv

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include \
		-I${LOCALASE}/include/ffmpeg \
		-I${LOCALBASE}/include/a52dec" \
		LIBFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS=	--disable-warnings
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
IGNORE=		requires an x86-32 processor, if you are using other platforms install avidemux2, which includes support for non-i386 systems
.endif

.if exists(${LOCALBASE}/lib/liba52.so.0)
WITH_A52=	yes
.endif

.if exists(${LOCALBASE}/lib/libxvidcore.so.2)
WITH_XVID=	yes
.endif

.if defined(WITH_XVID)
LIB_DEPENDS+=	xvidcore.2:${PORTSDIR}/multimedia/xvid
CONFIGURE_ARGS+=	--with-xvid-as-decoder
.endif

.if defined(WITH_A52)
LIB_DEPENDS+=	a52.0:${PORTSDIR}/audio/liba52
.endif

pre-everything::
.if !defined(WITH_XVID)
	@${ECHO_MSG} "To enable xvid as the decoder define WITH_XVID."
.endif

.if !defined(WITH_A52)
	@${ECHO_MSG} "To enable A/52 support define WITH_A52."
.endif

post-patch:
	@${TOUCH} ${WRKSRC}/*
	@${REINPLACE_CMD} 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
