# Created by: Wen Heping <wenheping@gmail.com>

PORTNAME=	HTTP_Request2
DISTVERSION=	2.4.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	www pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PEAR classes providing an easy way to perform HTTP requests

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/docs/LICENSE

BUILD_DEPENDS=	${PEARDIR}/Net/URL2.php:net/pear-Net_URL2@${PHP_FLAVOR}
RUN_DEPENDS=	${PEARDIR}/Net/URL2.php:net/pear-Net_URL2@${PHP_FLAVOR}

USES=	pear

OPTIONS_DEFINE=	CURL FILEINFO ZLIB
CURL_DESC=	PHP CURL extension support
FILEINFO_DESC=	PHP FILEINFO extension support
ZLIB_DESC=	PECL ZLIB support

CURL_USES=	php
CURL_USE=	PHP=curl
FILEINFO_USES=	php
FILEINFO_USE=	PHP=fileinfo
ZLIB_USES=	php
ZLIB_USE=	PHP=zlib

.include <bsd.port.mk>
