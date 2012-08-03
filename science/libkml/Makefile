# New ports collection makefile for:	libkml
# Date created:				3rd Oct, 2009
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libkml
PORTVERSION=	1.2.0
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Library for parse, generate, and operate on KML

BUILD_DEPENDS=	${LOCALBASE}/include/expat.h:${PORTSDIR}/textproc/expat2 \
		${LOCALBASE}/bin/curl-config:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
