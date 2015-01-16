# Created by: Matthieu BOUTHORS <matthieu@labs.fr>
# $FreeBSD$

PORTNAME=	sslscan
PORTVERSION=	1.8.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	matthieu@labs.fr
COMMENT=	SSLScan is a fast SSL port scanner

LICENSE=	GPLv3

CFLAGS+=	-I${LOCALBASE}/include ${CPPFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${LIBS}
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
USE_OPENSSL=	yes

.include <bsd.port.mk>
