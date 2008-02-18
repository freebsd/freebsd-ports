# New ports collection makefile for:	openmovieeditor
# Date created:		20 Sep 2007
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	openmovieeditor
PORTVERSION=	0.0.20080209
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Simple non-linear movie editor

LIB_DEPENDS=	samplerate.1:${PORTSDIR}/audio/libsamplerate \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		gavl.0:${PORTSDIR}/multimedia/gavl \
		quicktime.0:${PORTSDIR}/multimedia/libquicktime \
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		jack.0:${PORTSDIR}/audio/jack \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GL=		yes
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include"

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|machine/soundcard.h|sys/soundcard.h|' \
		${WRKSRC}/src/portaudio/pa_unix_oss.c

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}/images
	${INSTALL_DATA} ${WRKSRC}/doc/style.css ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/tutorial.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/images/*.png ${DOCSDIR}/images
.endif

.include <bsd.port.mk>
