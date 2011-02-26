# Ports collection makefile for:  pear-XML_RPC2
# Date created:		11 September 2008
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	XML_RPC2
PORTVERSION=	1.0.7
CATEGORIES=	net devel pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	XML-RPC client/server library

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/Cache/Lite.php:${PORTSDIR}/sysutils/pear-Cache_Lite
RUN_DEPENDS=	${BUILD_DEPENDS}

PEAR_CATSRC=	yes
USE_PHP=	curl

FILES=		XML/RPC2/Backend/Php/Value/Array.php \
		XML/RPC2/Backend/Php/Value/Base64.php \
		XML/RPC2/Backend/Php/Value/Boolean.php \
		XML/RPC2/Backend/Php/Value/Datetime.php \
		XML/RPC2/Backend/Php/Value/Double.php \
		XML/RPC2/Backend/Php/Value/Integer.php \
		XML/RPC2/Backend/Php/Value/Scalar.php \
		XML/RPC2/Backend/Php/Value/String.php \
		XML/RPC2/Backend/Php/Value/Struct.php \
		XML/RPC2/Backend/Php/Client.php \
		XML/RPC2/Backend/Php/Request.php \
		XML/RPC2/Backend/Php/Response.php \
		XML/RPC2/Backend/Php/Server.php \
		XML/RPC2/Backend/Php/Value.php \
		XML/RPC2/Backend/Xmlrpcext/Client.php \
		XML/RPC2/Backend/Xmlrpcext/Server.php \
		XML/RPC2/Backend/Xmlrpcext/Value.php \
		XML/RPC2/Server/CallHandler/Class.php \
		XML/RPC2/Server/CallHandler/Instance.php \
		XML/RPC2/Server/CallHandler.php \
		XML/RPC2/Server/Method.php \
		XML/RPC2/Util/HTTPRequest.php \
		XML/RPC2/Backend.php \
		XML/RPC2/CachedClient.php \
		XML/RPC2/CachedServer.php \
		XML/RPC2/Client.php \
		XML/RPC2/Exception.php \
		XML/RPC2/Server.php \
		XML/RPC2/Value.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
