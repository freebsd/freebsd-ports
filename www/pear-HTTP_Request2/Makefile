# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	HTTP_Request2
PORTVERSION=	2.1.1
PORTEPOCH=	1
CATEGORIES=	www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR classes providing an easy way to perform HTTP requests

BUILD_DEPENDS=	${PEARDIR}/Net/URL2.php:${PORTSDIR}/net/pear-Net_URL2
RUN_DEPENDS=	${PEARDIR}/Net/URL2.php:${PORTSDIR}/net/pear-Net_URL2

OPTIONS_DEFINE=	CURL FILEINFO ZLIB
CURL_DESC=	PHP CURL extension support
FILEINF_DESC=	PHP FILEINFO extension support
ZLI_DESC=	PECL ZLIB support

PEAR_AUTOINSTALL=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCURL}
USE_PHP+=	curl
.endif

.if ${PORT_OPTIONS:MFILEINFO}
USE_PHP+=	fileinfo
.endif

.if ${PORT_OPTIONS:MZLIB}
USE_PHP+=	zlib
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.mk>
