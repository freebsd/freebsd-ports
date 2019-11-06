# $FreeBSD$

PORTNAME=	ffms2
DISTVERSION=	2.23
PORTREVISION=	11
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	FFmpeg-based source library and VapourSynth plugin

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

.if ${MACHINE_ARCH} == amd64 || ${MACHINE_ARCH} == i386
BUILD_DEPENDS=	${LOCALBASE}/include/vapoursynth/VSHelper.h:multimedia/vapoursynth
.endif
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

USE_GITHUB=	yes
GH_ACCOUNT=	FFMS

USES=		compiler:c++11-lib gmake libtool pathfix pkgconfig
.if ${MACHINE_ARCH} == amd64 || ${MACHINE_ARCH} == i386
EXCLUDE=	VSHelper.h VSScript.h VapourSynth.h
EXTRACT_AFTER_ARGS=${EXCLUDE:S,^,--exclude ,}
.endif
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static
.if ${MACHINE_ARCH} == amd64 || ${MACHINE_ARCH} == i386
CPPFLAGS+=	`pkg-config vapoursynth --cflags`
.endif
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
DATADIR=	${PREFIX}/lib/vapoursynth

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/^dist_doc_DATA/s,=,& \
			doc/${PORTNAME}-vapoursynth.md,' \
		${WRKSRC}/Makefile.in

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${LN} -sf ../lib${PORTNAME}.so ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
