# Created by: johnpupu <johnpupu@gmail.com>
# $FreeBSD$

PORTNAME=	yaf
DISTVERSION=	3.0.9
CATEGORIES=	www

MAINTAINER=	miwi@freeBSD.org
COMMENT=	MVC framework written as a C PHP extension

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpcre.so:devel/pcre

CONFIGURE_ARGS=	--with-php-config=${LOCALBASE}/bin/php-config
USES=		localbase php:pecl

.include <bsd.port.mk>
