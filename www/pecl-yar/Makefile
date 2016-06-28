# Created by: John Chen <johnpupu@gmail.com>
# $FreeBSD$

PORTNAME=	yar
PORTVERSION=	1.2.5
CATEGORIES=	www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	johnpupu@gmail.com
COMMENT=	Yar (Yet another RPC framework) is a light, concurrent RPC framework

LICENSE=	PHP301

BROKEN_powerpc64=	Does not build

USES=		php:ext tar:tgz
USE_PHP=	json:build curl:build
IGNORE_WITH_PHP=	70

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--with-php-config=${PREFIX}/bin/php-config

OPTIONS_DEFINE=	MSGPACK
MSGPACK_DESC=	Enable MSGPACK module
MSGPACK_BUILD_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/msgpack.so:devel/pecl-msgpack
MSGPACK_RUN_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/msgpack.so:devel/pecl-msgpack

.include <bsd.port.mk>
