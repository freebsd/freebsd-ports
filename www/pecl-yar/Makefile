# Created by: John Chen <johnpupu@gmail.com>

PORTNAME=	yar
PORTVERSION=	2.2.0
CATEGORIES=	www

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Yar (Yet another RPC framework) is a light, concurrent RPC framework

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		localbase:ldflags php:pecl
USE_PHP=	curl json:build

OPTIONS_DEFINE=	MSGPACK
OPTIONS_DEFAULT=MSGPACK
MSGPACK_DESC=	Enable MSGPACK module

MSGPACK_BUILD_DEPENDS=	${PECL_PKGNAMEPREFIX}msgpack>=0:devel/pecl-msgpack@${PHP_FLAVOR}
MSGPACK_RUN_DEPENDS=	${PECL_PKGNAMEPREFIX}msgpack>=0:devel/pecl-msgpack@${PHP_FLAVOR}

.include <bsd.port.mk>
