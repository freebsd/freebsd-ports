# Ports collection makefile for:  pear-Services_Amazon_S3
# Date created:			  23 Nov ,2009
# Whom:				  Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Services_Amazon_S3
PORTVERSION=	0.3.0
CATEGORIES=	www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP API for Amazon S3 (Simple Storage Service)

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/HTTP/Request2.php:${PORTSDIR}/www/pear-HTTP_Request2 \
		${PEARDIR}/Crypt/HMAC2.php:${PORTSDIR}/security/pear-Crypt_HMAC2
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	spl

CATEGORY=	Services
FILES=		Amazon/S3.php \
		Amazon/S3/AccessControlList.php \
		Amazon/S3/AccessDeniedException.php\
		Amazon/S3/Exception.php \
		Amazon/S3/NotFoundException.php \
		Amazon/S3/ObjectIterator.php \
		Amazon/S3/Prefix.php \
		Amazon/S3/Resource/Bucket.php \
		Amazon/S3/Resource/Object.php \
		Amazon/S3/Resource.php \
		Amazon/S3/ServerErrorException.php \
		Amazon/S3/Stream.php
TESTS=		AllTests.php StreamTest.php\
		Test.php config.php.dist

post-extract:
		@cd ${WRKSRC} && ${MV} Services/Amazon .

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
