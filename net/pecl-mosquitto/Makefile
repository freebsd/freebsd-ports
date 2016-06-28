# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	mosquitto
PORTVERSION=	0.3.0
CATEGORIES=	net pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DISTNAME=	Mosquitto-${PORTVERSION}
DIST_SUBDIR=	PECL

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Extension for libmosquitto

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	mosquitto>=0:net/mosquitto

USES=		php:ext tar:tgz
IGNORE_WITH_PHP=	70

.include <bsd.port.mk>
