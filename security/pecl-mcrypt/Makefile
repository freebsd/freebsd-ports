# $FreeBSD$

PORTNAME=	mcrypt
PORTVERSION=	1.0.1
CATEGORIES=	security pear

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	PHP extension for mcrypt, removed in PHP 7.2

LICENSE=	PHP301

IGNORE_WITH_PHP=	56 70 71

LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libmcrypt.so:security/libmcrypt

USES=	php:pecl

.include <bsd.port.mk>
