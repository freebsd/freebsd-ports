# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ffmpeg2theora
PORTVERSION=	0.30
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://v2v.cc/~j/ffmpeg2theora/downloads/

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Reencode many media file formats to Ogg Theora

LICENSE=	GPLv3

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libkate.so:multimedia/libkate \
		libtheora.so:multimedia/libtheora

USES=		iconv pkgconfig scons tar:bzip2
MAKE_ARGS=	APPEND_CCFLAGS="${CFLAGS} ${CPPFLAGS}" \
		APPEND_LINKFLAGS="${LDFLAGS} ${LIBS}"

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib ${ICONV_LIB}

PLIST_FILES=	bin/ffmpeg2theora man/man1/ffmpeg2theora.1.gz

.include <bsd.port.mk>
