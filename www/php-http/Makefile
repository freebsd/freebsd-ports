PORTNAME=	http
DISTVERSION=	4.3.1
CATEGORIES=	www
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Extended HTTP Support
WWW=		https://github.com/m6w6/ext-http

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/raphf.so:devel/php-raphf@${PHP_FLAVOR} \
		re2c:devel/re2c \
		bash>0:shells/bash
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libevent.so:devel/libevent \
		libicudata.so:devel/icu
RUN_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/raphf.so:devel/php-raphf@${PHP_FLAVOR}

USES=		cpe php:ext
USE_GITHUB=	yes
GH_ACCOUNT=	m6w6
GH_PROJECT=	ext-${PORTNAME}
USE_PHP=	iconv:build zlib:build
IGNORE_WITH_PHP=	86

CPE_VENDOR=	php
CPE_PRODUCT=	ext-http

CONFIGURE_SHELL=	${LOCALBASE}/bin/bash

.include <bsd.port.mk>
