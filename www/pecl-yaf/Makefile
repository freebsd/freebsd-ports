# Created by: johnpupu <johnpupu@gmail.com>
# $FreeBSD$

PORTNAME=	yaf
PORTVERSION=	2.3.3
CATEGORIES=	www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	johnpupu@gmail.com
COMMENT=	MVC framework written as a C PHP extension

LICENSE=	PHP301

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--with-php-config=${PREFIX}/bin/php-config

PHP_MODNAME=	${PORTNAME:tl}
USE_PHP=	yes
USE_PHPEXT=	yes
USE_PHPIZE=	yes
IGNORE_WITH_PHP=	56

.include <bsd.port.mk>
