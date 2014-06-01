# Created by: Matthieu BOUTHORS <matthieu@labs.fr>
# $FreeBSD$

PORTNAME=	sslscan
PORTVERSION=	1.8.2
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	matthieu@labs.fr
COMMENT=	SSLScan is a fast SSL port scanner

LICENSE=	GPLv3

MAKE_ARGS=	CC="${CC}" CFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
