PORTNAME=	mosquitto
PORTVERSION=	0.4.0
CATEGORIES=	net pear
DISTNAME=	Mosquitto-${PORTVERSION}

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Extension for libmosquitto

LICENSE=	BSD3CLAUSE

DEPRECATED=	Requires php 7.4 which is set to expire on 2022-11-29
EXPIRATION_DATE=2022-11-28

BUILD_DEPENDS=	mosquitto>=0:net/mosquitto

USES=		php:pecl
IGNORE_WITH_PHP=	80 81 82

.include <bsd.port.mk>
