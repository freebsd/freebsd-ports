# New ports collection makefile for:	mod_h264_streaming
# Date created:				May 14, 2009
# Whom:					Li-Wen Hsu <lwhsu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_h264_streaming
PORTVERSION=	2.2.7
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://h264.code-shop.com/download/
DISTNAME=	apache_${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	apache22

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Apache H264 streaming module

USE_APACHE=	22+

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-apxs="${APXS}"

RESTRICTED=	no-commercial-use

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PLIST_SUB=	SED=${SED}

.include <bsd.port.mk>
