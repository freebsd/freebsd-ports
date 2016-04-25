# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	http
PORTVERSION=	3.0.1
CATEGORIES=	www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DISTNAME=	pecl_${PORTNAME}-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Extended HTTP Support

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	Does not build

BUILD_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/raphf.so:devel/pecl-raphf2 \
		${LOCALBASE}/lib/php/${PHP_EXT_DIR}/propro.so:devel/pecl-propro2 \
		re2c:devel/re2c
RUN_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/raphf.so:devel/pecl-raphf2 \
		${LOCALBASE}/lib/php/${PHP_EXT_DIR}/propro.so:devel/pecl-propro2
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libevent.so:devel/libevent2

PHP_DEFAULT=	7.0
IGNORE_WITH_PHP=	55 56
USES=		tar:tgz
USE_PHP=	yes
USE_PHPEXT=	yes
CONFLICTS=	pecl-http[12]*

.include <bsd.port.mk>
