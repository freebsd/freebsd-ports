# Created by: johnpupu <johnpupu@gmail.com>
# $FreeBSD$

PORTNAME=	taint
PORTVERSION=	1.2.2
CATEGORIES=	security
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	johnpupu@gmail.com
COMMENT=	Extension used for detecting XSS codes (tainted string)

DEPRECATED=	${IGNORE}
EXPIRATION_DATE=2016-03-15

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--with-php-config=${PREFIX}/bin/php-config

USE_PHP=	yes
USE_PHPEXT=	yes
USE_PHPIZE=	yes
IGNORE_WITH_PHP=	55 56 70

.include <bsd.port.mk>
