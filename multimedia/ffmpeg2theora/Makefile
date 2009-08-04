# New ports collection makefile for:	ffmpeg2theora
# Date created:				Sat 19 Oct 2008
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	ffmpeg2theora
PORTVERSION=	0.24
CATEGORIES=	multimedia
MASTER_SITES=	http://v2v.cc/~j/ffmpeg2theora/

MAINTAINER=	anders@FreeBSD.org
COMMENT=	Reencode many media file formats to Ogg Theora

LIB_DEPENDS=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		theora.0:${PORTSDIR}/multimedia/libtheora \
		kate.1:${PORTSDIR}/multimedia/libkate

USE_BZIP2=	yes
USE_SCONS=	yes

SCONS_ENV+=	APPEND_LINKFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib" \
		APPEND_CFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include"

MAN1=		ffmpeg2theora.1
PLIST_FILES=	bin/ffmpeg2theora

.include <bsd.port.mk>
