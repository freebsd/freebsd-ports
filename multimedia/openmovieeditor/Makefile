# New ports collection makefile for:	openmovieeditor
# Date created:		20 Sep 2007
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	openmovieeditor
PORTVERSION=	0.0.20090105
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simple non-linear movie editor

LIB_DEPENDS=	samplerate.1:${PORTSDIR}/audio/libsamplerate \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		gavl.1:${PORTSDIR}/multimedia/gavl \
		gmerlin_avdec.1:${PORTSDIR}/multimedia/gmerlin-avdecoder \
		gmerlin.0:${PORTSDIR}/multimedia/gmerlin \
		quicktime.0:${PORTSDIR}/multimedia/libquicktime \
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		jack.0:${PORTSDIR}/audio/jack \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk \
		portaudio.2:${PORTSDIR}/audio/portaudio2
BUILD_DEPENDS=	${LOCALBASE}/lib/libmpeg3.a:${PORTSDIR}/multimedia/libmpeg3 \
		${LOCALBASE}/lib/libquicktime/lqt_lame.so:${PORTSDIR}/multimedia/libquicktime-lame
RUN_DEPENDS=	${LOCALBASE}/lib/libquicktime/lqt_lame.so:${PORTSDIR}/multimedia/libquicktime-lame

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GL=		yes
USE_GNOME=	glib20
CONFIGURE_ARGS=	CPPFLAGS="-I${WRKSRC}/src/tinyxml -I${LOCALBASE}/include/portaudio2 -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib/portaudio2 -L${LOCALBASE}/lib"

PORTDOCS=	*

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}/images
	${INSTALL_DATA} ${WRKSRC}/doc/style.css ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/tutorial.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/images/*.png ${DOCSDIR}/images
.endif

.include <bsd.port.mk>
