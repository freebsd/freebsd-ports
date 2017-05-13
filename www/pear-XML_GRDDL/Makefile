# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	XML_GRDDL
PORTVERSION=	0.2.0
CATEGORIES=	www pear

MAINTAINER=	joneum@bsdproject.de
COMMENT=	PHP library for dealing with GRDDL

BUILD_DEPENDS=	${PEARDIR}/HTTP/Request.php:www/pear-HTTP_Request \
		${PEARDIR}/Net/URL.php:net/pear-Net_URL \
		${PEARDIR}/Log.php:sysutils/pear-Log \
		${PEARDIR}/Validate.php:devel/pear-Validate
RUN_DEPENDS=	${PEARDIR}/HTTP/Request.php:www/pear-HTTP_Request \
		${PEARDIR}/Net/URL.php:net/pear-Net_URL \
		${PEARDIR}/Log.php:sysutils/pear-Log \
		${PEARDIR}/Validate.php:devel/pear-Validate

BROKEN_powerpc64=	fails to package: Generating packing list with pear: Signal 11

USES=	pear
USE_PHP+=	xsl tidy

.include <bsd.port.mk>
