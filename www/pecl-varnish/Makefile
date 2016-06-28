# Created by: Jim Ohlstein <jim@ohlste.in>
# $FreeBSD$

PORTNAME=	varnish
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	jim@ohlste.in
COMMENT=	Varnish cache extension

LICENSE=	BSD2CLAUSE

BROKEN=		fails to build
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

BUILD_DEPENDS=	varnish4>=0:www/varnish4

USES=	php:ext tar:tgz
USE_PHP=	hash:build

IGNORE_WITH_PHP=	52

.include <bsd.port.mk>
