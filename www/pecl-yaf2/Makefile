# Created by: johnpupu <johnpupu@gmail.com>
# $FreeBSD$

PORTNAME=	yaf
PORTVERSION=	2.3.5
CATEGORIES=	www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
PKGNAMESUFFIX=	2
DIST_SUBDIR=	PECL

MAINTAINER=	johnpupu@gmail.com
COMMENT=	MVC framework written as a C PHP extension

LICENSE=	PHP301

LIB_DEPENDS=	libpcre.so:devel/pcre

PORTSCOUT=	limit:^2\.

USES=		localbase php:ext tar:tgz
IGNORE_WITH_PHP=70 71

.include <bsd.port.mk>
