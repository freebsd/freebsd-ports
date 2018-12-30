# Created by: John Chen <johnpupu@gmail.com>
# $FreeBSD$

PORTNAME=	yar
DISTVERSION=	2.0.5
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Yar (Yet another RPC framework) is a light, concurrent RPC framework

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

IGNORE_WITH_PHP=	56

USES=		localbase php:pecl
USE_PHP=	json:build curl:build

OPTIONS_DEFINE=	MSGPACK
MSGPACK_DESC=	Enable MSGPACK module
MSGPACK_BUILD_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/msgpack.so:devel/pecl-msgpack@${PHP_FLAVOR}
MSGPACK_RUN_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/msgpack.so:devel/pecl-msgpack@${PHP_FLAVOR}

.include <bsd.port.mk>
