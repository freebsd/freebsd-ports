# Created by: johnpupu <johnpupu@gmail.com>
# $FreeBSD$

PORTNAME=	yaf
PORTVERSION=	3.0.5
CATEGORIES=	www

MAINTAINER=	johnpupu@gmail.com
COMMENT=	MVC framework written as a C PHP extension

LICENSE=	PHP301

LIB_DEPENDS=	libpcre.so:devel/pcre

CONFIGURE_ARGS=	--with-php-config=${LOCALBASE}/bin/php-config
USES=		localbase php:pecl
IGNORE_WITH_PHP=56

.include <bsd.port.mk>
