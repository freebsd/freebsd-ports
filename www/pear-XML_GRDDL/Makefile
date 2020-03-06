# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	XML_GRDDL
PORTVERSION=	0.2.0
CATEGORIES=	www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP library for dealing with GRDDL

BUILD_DEPENDS=	${PEARDIR}/HTTP/Request.php:www/pear-HTTP_Request@${PHP_FLAVOR} \
		${PEARDIR}/Net/URL.php:net/pear-Net_URL@${PHP_FLAVOR} \
		${PEARDIR}/Log.php:sysutils/pear-Log@${PHP_FLAVOR} \
		${PEARDIR}/Validate.php:devel/pear-Validate@${PHP_FLAVOR}
RUN_DEPENDS=	${PEARDIR}/HTTP/Request.php:www/pear-HTTP_Request@${PHP_FLAVOR} \
		${PEARDIR}/Net/URL.php:net/pear-Net_URL@${PHP_FLAVOR} \
		${PEARDIR}/Log.php:sysutils/pear-Log@${PHP_FLAVOR} \
		${PEARDIR}/Validate.php:devel/pear-Validate@${PHP_FLAVOR}

USES=		pear php
USE_PHP=	xsl tidy

.include <bsd.port.mk>
