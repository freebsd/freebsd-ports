# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	XML_RPC2
PORTVERSION=	1.1.3
CATEGORIES=	net devel pear

MAINTAINER=	joneum@bsdproject.de
COMMENT=	XML-RPC client/server library

LICENSE=	PHP301

BUILD_DEPENDS=	${PEARDIR}/Cache/Lite.php:sysutils/pear-Cache_Lite \
		${PEARDIR}/HTTP/Request2.php:www/pear-HTTP_Request2
RUN_DEPENDS=	${PEARDIR}/Cache/Lite.php:sysutils/pear-Cache_Lite \
		${PEARDIR}/HTTP/Request2.php:www/pear-HTTP_Request2

USE_PHP=	curl
USES=	pear

.include <bsd.port.mk>
