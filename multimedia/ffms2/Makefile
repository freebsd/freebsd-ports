# $FreeBSD$

PORTNAME=	ffms2
DISTVERSION=	2.23
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	FFmpeg-based source library and VapourSynth plugin

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/vapoursynth/VSHelper.h:multimedia/vapoursynth
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

USE_GITHUB=	yes
GH_ACCOUNT=	FFMS

USES=		compiler:c++11-lib gmake libtool pathfix pkgconfig
EXCLUDE=	VSHelper.h VSScript.h VapourSynth.h
EXTRACT_AFTER_ARGS=${EXCLUDE:S,^,--exclude ,}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static
CPPFLAGS+=	-D_GLIBCXX_USE_C99 # XXX ports/193528
CPPFLAGS+=	`pkg-config vapoursynth --cflags`
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
DATADIR=	${PREFIX}/lib/vapoursynth

post-patch:
	@${REINPLACE_CMD} -e '/^dist_doc_DATA/s,=,& \
			doc/${PORTNAME}-vapoursynth.md,' \
		${WRKSRC}/Makefile.in

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${LN} -sf ../lib${PORTNAME}.so ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
