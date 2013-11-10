# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libkml
PORTVERSION=	1.2.0
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for parse, generate, and operate on KML

LICENSE=	BSD

BUILD_DEPENDS=	${LOCALBASE}/include/expat.h:${PORTSDIR}/textproc/expat2 \
		${LOCALBASE}/bin/curl-config:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
USE_GCC=	yes
USES=		gmake
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include -Wno-long-long
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
