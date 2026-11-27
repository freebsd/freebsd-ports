PORTNAME=	mcrypt
DISTVERSION=	1.0.9
CATEGORIES=	security
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	PHP extension for mcrypt, removed in PHP 7.2
WWW=		https://pecl.php.net/package/mcrypt \
		https://github.com/php/pecl-encryption-mcrypt/

LICENSE=	PHP-3.01
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libmcrypt.so:security/libmcrypt

USES=		php:ext
USE_GITHUB=	yes
GH_ACCOUNT=	php
GH_PROJECT=	pecl-encryption-${PORTNAME}
IGNORE_WITH_PHP=	86

.include <bsd.port.mk>
