# $FreeBSD$

PORTNAME=	stomp
PORTVERSION=	2.0.0
CATEGORIES=	net-im pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
PKGNAMESUFFIX=	2
DIST_SUBDIR=	PECL

MAINTAINER=	dbaio@bsd.com.br
COMMENT=	PECL extension of stomp client

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

PORTSCOUT=	limit:^2.*

USES=		php:ext tar:tgz
PHP_VER=	70
IGNORE_WITH_PHP=	55 56
CONFLICTS=	pecl-stomp-1*

.include <bsd.port.mk>
