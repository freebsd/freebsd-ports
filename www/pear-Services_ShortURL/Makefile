# Ports collection makefile for:  pear-Services_ShortURL
# Date created:			  06 April 2011
# Whom:				  Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Services_ShortURL
PORTVERSION=	0.3.1
CATEGORIES=	www pear

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Abstract PHP5 interface for shortening and expanding short URLs

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/HTTP/Request2.php:${PORTSDIR}/www/pear-HTTP_Request2

USE_PHP=	simplexml pcre spl

CATEGORY=	Services
PEAR_CATSRC=	yes

FILES=		ShortURL/Bitly.php \
		ShortURL/Common.php \
		ShortURL/Digg.php \
		ShortURL/Exception/CouldNotExpand.php \
		ShortURL/Exception/CouldNotShorten.php \
		ShortURL/Exception/InvalidOptions.php \
		ShortURL/Exception/NotImplemented.php \
		ShortURL/Exception/UnknownService.php \
		ShortURL/Exception.php \
		ShortURL/Googl.php \
		ShortURL/Interface.php \
		ShortURL/Isgd.php \
		ShortURL/Shortie.php \
		ShortURL/TinyURL.php \
		ShortURL/Trim.php \
		ShortURL.php

TESTS=		AllTests.php Services/ShortURLTest.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
