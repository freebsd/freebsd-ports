# Created by: John Chen <johnpupu@gmail.com>
# $FreeBSD$

PORTNAME=	yar
PORTVERSION=	1.2.0
CATEGORIES=	www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	johnpupu@gmail.com
COMMENT=	Yar (Yet another RPC framework) is a light, concurrent RPC framework

LICENSE=	PHP301

PHP_MODNAME=	yar
USE_PHP=	json curl
USE_PHPEXT=	yes
USE_PHPIZE=	yes
USE_PHP_BUILD=	yes

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--with-php-config=${PREFIX}/bin/php-config

OPTIONS_DEFINE=	MSGPACK
MSGPACK_DESC=	Enable MSGPACK module
MSGPACK_BUILD_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/msgpack.so:${PORTSDIR}/devel/pecl-msgpack
MSGPACK_RUN_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/msgpack.so:${PORTSDIR}/devel/pecl-msgpack

.include <bsd.port.mk>
