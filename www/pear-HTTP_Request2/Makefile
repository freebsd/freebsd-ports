# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	HTTP_Request2
PORTVERSION=	2.3.0
PORTEPOCH=	1
CATEGORIES=	www pear

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	PEAR classes providing an easy way to perform HTTP requests

BUILD_DEPENDS=	${PEARDIR}/Net/URL2.php:net/pear-Net_URL2@${PHP_FLAVOR}
RUN_DEPENDS=	${PEARDIR}/Net/URL2.php:net/pear-Net_URL2@${PHP_FLAVOR}

OPTIONS_DEFINE=	CURL FILEINFO ZLIB
CURL_DESC=	PHP CURL extension support
FILEINFO_DESC=	PHP FILEINFO extension support
ZLIB_DESC=	PECL ZLIB support

USES=	pear

CURL_USE=	PHP=curl
FILEINFO_USE=	PHP=fileinfo
ZLIB_USE=	PHP=zlib

.include <bsd.port.mk>
