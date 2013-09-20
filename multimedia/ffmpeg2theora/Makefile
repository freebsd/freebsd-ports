# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ffmpeg2theora
PORTVERSION=	0.29
CATEGORIES=	multimedia
MASTER_SITES=	http://v2v.cc/~j/ffmpeg2theora/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Reencode many media file formats to Ogg Theora

LICENSE=	GPLv3

LIB_DEPENDS=	avcodec:${PORTSDIR}/multimedia/ffmpeg \
		kate:${PORTSDIR}/multimedia/libkate \
		theora:${PORTSDIR}/multimedia/libtheora

USE_BZIP2=	yes
USES=		iconv pkgconfig
USE_SCONS=	yes
SCONS_BUILDENV=	CC="${CC}" CCFLAGS="${CFLAGS}" \
		APPEND_CCFLAGS="${CPPFLAGS}" APPEND_LINKFLAGS="${LDFLAGS}"

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

MAN1=		ffmpeg2theora.1
PLIST_FILES=	bin/ffmpeg2theora

NO_STAGE=	yes
.include <bsd.port.mk>
