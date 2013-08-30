# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	openmovieeditor
PORTVERSION=	0.0.20090105
PORTREVISION=	9
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simple non-linear movie editor

LIB_DEPENDS=	samplerate:${PORTSDIR}/audio/libsamplerate \
		sndfile:${PORTSDIR}/audio/libsndfile \
		gavl:${PORTSDIR}/multimedia/gavl \
		gmerlin_avdec:${PORTSDIR}/multimedia/gmerlin-avdecoder \
		gmerlin:${PORTSDIR}/multimedia/gmerlin \
		quicktime:${PORTSDIR}/multimedia/libquicktime \
		avcodec:${PORTSDIR}/multimedia/ffmpeg \
		jack:${PORTSDIR}/audio/jack \
		fltk:${PORTSDIR}/x11-toolkits/fltk \
		portaudio:${PORTSDIR}/audio/portaudio2
BUILD_DEPENDS=	${LOCALBASE}/lib/libmpeg3.a:${PORTSDIR}/multimedia/libmpeg3 \
		${LOCALBASE}/lib/libquicktime/lqt_lame.so:${PORTSDIR}/multimedia/libquicktime-lame
RUN_DEPENDS=	${LOCALBASE}/lib/libquicktime/lqt_lame.so:${PORTSDIR}/multimedia/libquicktime-lame

USES=		gmake pkgconfig
GNU_CONFIGURE=	yes
USE_GL=		yes
USE_GNOME=	glib20
CONFIGURE_ARGS=	CPPFLAGS="-I${WRKSRC}/src/tinyxml -I${LOCALBASE}/include/portaudio2 -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib/portaudio2 -L${LOCALBASE}/lib `fltk-config --ldflags`"
USE_DOS2UNIX=	yes

PORTDOCS=	*

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/images
	${INSTALL_DATA} ${WRKSRC}/doc/style.css ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/tutorial.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/images/*.png ${DOCSDIR}/images
.endif

.include <bsd.port.mk>
