# Created by: Wen Heping <wenheping@gmail.com>

PORTNAME=	HTTP_Request2
PORTVERSION=	2.5.1
PORTEPOCH=	1
CATEGORIES=	www pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PEAR classes providing an easy way to perform HTTP requests

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/docs/LICENSE

RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}Net_URL2>=2.2.0:net/pear-Net_URL2@${PHP_FLAVOR}

USES=		pear

NO_ARCH=	yes

OPTIONS_DEFINE=	CURL FILEINFO ZLIB
CURL_DESC=	PHP CURL extension support
FILEINFO_DESC=	PHP FILEINFO extension support
ZLIB_DESC=	PECL ZLIB support

CURL_USE=	PHP=curl
FILEINFO_USE=	PHP=fileinfo
ZLIB_USE=	PHP=zlib

.include <bsd.port.mk>
