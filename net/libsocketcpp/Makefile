# Created by: ijliao
# $FreeBSD$

PORTNAME=	libsocketcpp
PORTVERSION=	1.0.7
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/libsocket/${PORTNAME}-stable/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ wrapper library to the sockets

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Uses gets(3)
EXPIRATION_DATE=	2017-11-05

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsocketcpp.so

.include <bsd.port.mk>
