# Created by: John Chen <johnpupu@gmail.com>
# $FreeBSD$

PORTNAME=	yar
PORTVERSION=	1.2.5
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Yar (Yet another RPC framework) is a light, concurrent RPC framework

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	PHP301

USES=		localbase php:pecl
USE_PHP=	json:build curl:build
IGNORE_WITH_PHP=71 72 73

OPTIONS_DEFINE=	MSGPACK
MSGPACK_DESC=	Enable MSGPACK module
MSGPACK_BUILD_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/msgpack.so:devel/pecl-msgpack0@${PHP_FLAVOR}
MSGPACK_RUN_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/msgpack.so:devel/pecl-msgpack0@${PHP_FLAVOR}

.include <bsd.port.mk>
