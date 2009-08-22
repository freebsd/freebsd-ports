# Ports collection makefile for:  pear-HTTP_Request2
# Date created:			  08 Jan 2009
# Whom:				  Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	HTTP_Request2
PORTVERSION=	0.4.0
CATEGORIES=	www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR classes providing an easy way to perform HTTP requests

BUILD_DEPENDS=	${PEARDIR}/Net/URL2.php:${PORTSDIR}/net/pear-Net_URL2
RUN_DEPENDS=	${BUILD_DEPENDS}

OPTIONS=	CURL "PHP CURL extension support" off \
		FILEINFO "PHP FILEINFO extension support" off \
		ZLIB "PECL ZLIB support" off

CATEGORY=	HTTP
FILES=		Request2.php \
		Request2/Exception.php Request2/Adapter.php \
		Request2/MultipartBody.php Request2/Response.php \
		Request2/Adapter/Curl.php \
		Request2/Adapter/Mock.php \
		Request2/Adapter/Socket.php \
		Request2/Observer/Log.php
TESTS=		AllTests.php ObserverTest.php Request2Test.php \
		Request2/AllTests.php \
		Request2/MultipartBodyTest.php \
		Request2/ResponseTest.php \
		Request2/Adapter/AllTests.php \
		Request2/Adapter/MockTest.php \
		_files/bug_15305 _files/response_cookies\
		_files/response_gzip_broken _files/empty.gif \
		_files/response_deflate _files/response_headers \
		_files/plaintext.txt _files/response_gzip

.include <bsd.port.pre.mk>

.if defined(WITH_CURL)
USE_PHP+=	curl
.endif

.if defined(WITH_FILEINFO)
USE_PHP+=	fileinfo
.endif

.if defined(WITH_ZLIB)
USE_PHP+=	zlib
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
