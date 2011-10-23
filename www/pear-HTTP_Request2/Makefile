# Ports collection makefile for:  pear-HTTP_Request2
# Date created:			  08 Jan 2009
# Whom:				  Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	HTTP_Request2
PORTVERSION=	2.0.0
PORTEPOCH=	1
CATEGORIES=	www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR classes providing an easy way to perform HTTP requests

BUILD_DEPENDS=	${PEARDIR}/Net/URL2.php:${PORTSDIR}/net/pear-Net_URL2
RUN_DEPENDS=	${PEARDIR}/Net/URL2.php:${PORTSDIR}/net/pear-Net_URL2

OPTIONS=	CURL "PHP CURL extension support" off \
		FILEINFO "PHP FILEINFO extension support" off \
		ZLIB "PECL ZLIB support" off

PEAR_AUTOINSTALL=	yes

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
