# New ports collection makefile for:	ffmpeg2theora
# Date created:				Sat 19 Oct 2008
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
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
USE_ICONV=	yes
USE_SCONS=	yes
SCONS_BUILDENV=	CC="${CC}" CCFLAGS="${CFLAGS}" \
		APPEND_CCFLAGS="${CPPFLAGS}" APPEND_LINKFLAGS="${LDFLAGS}"
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

MAN1=		ffmpeg2theora.1
PLIST_FILES=	bin/ffmpeg2theora

.include <bsd.port.mk>
