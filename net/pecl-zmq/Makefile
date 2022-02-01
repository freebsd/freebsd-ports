PORTNAME=	zmq
PORTVERSION=	1.1.3
PORTREVISION=	3
CATEGORIES=	net pear

MAINTAINER=	garga@FreeBSD.org
COMMENT=	PHP bindings for ZeroMQ

LICENSE=	BSD3CLAUSE

DEPRECATED=	Requires php 7.4 which is set to expire on 2022-11-29
EXPIRATION_DATE=2022-11-28

LIB_DEPENDS=	libzmq.so:net/libzmq4

USES=		php:pecl pkgconfig
IGNORE_WITH_PHP=	80 81

.include <bsd.port.mk>
