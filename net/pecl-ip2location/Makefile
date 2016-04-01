# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	ip2location
PORTVERSION=	6.0.4
CATEGORIES=	net pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Get geo location information of an IP address

LICENSE=	PHP301

LIB_DEPENDS=	libIP2Location.so:net/ip2location

USES=		tar:tgz
USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
IGNORE_WITH_PHP=	70

.include <bsd.port.mk>
