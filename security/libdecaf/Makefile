# $FreeBSD$

PORTNAME=	libdecaf
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/ed448goldilocks/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Implementation of elliptic curve cryptography

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake python:2.7 tar:tgz
USE_LDCONFIG=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
