# New ports collection makefile for:	mod_h264_streaming
# Date created:				May 14, 2009
# Whom:					Li-Wen Hsu <lwhsu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_h264_streaming
PORTVERSION=	2.0
CATEGORIES=	www
MASTER_SITES=	http://www.cs.nctu.edu.tw/~lwhsu/ports/distfiles/
DIST_SUBDIR=	apache22

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Apache H264 streaming module

USE_BZIP2=	yes
USE_APACHE=	22+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
SRC_FILE=	mod_h264_streaming.c moov.c

RESTRICTED=	no-commercial-use

.include <bsd.port.mk>
