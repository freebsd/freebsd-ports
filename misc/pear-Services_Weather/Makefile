# Created by: Thierry Thomas (<thierry@FreeBSD.org>)
# $FreeBSD$

PORTNAME=	Services_Weather
PORTVERSION=	1.4.6
PORTEPOCH=	1
CATEGORIES=	misc www pear geography

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	PEAR interface to various online weather-services

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PEARDIR}/HTTP/Request.php:www/pear-HTTP_Request

PORTSCOUT=	skipv:1.4.7

NO_ARCH=	yes
USE_PHP=	ctype pcre
USES=		pear

OPTIONS_DEFINE=	PEAR_NET_FTP PEAR_CACHE PEAR_DB PEAR_SOAP PEAR_XML_SERIALIZER
PEAR_NET_FTP_DESC=	PEAR::Net::FTP support
PEAR_CACHE_DESC=PEAR::Cache support
PEAR_DB_DESC=	PEAR::DB support
PEAR_SOAP_DESC=	PEAR::SOAP support
PEAR_XML_SERIALIZER_DESC=	PEAR::XML::Serializer support

PEAR_NET_FTP_BUILD_DEPENDS=	${PEARDIR}/Net/FTP.php:ftp/pear-Net_FTP
PEAR_CACHE_BUILD_DEPENDS=	${PEARDIR}/Cache.php:sysutils/pear-Cache
PEAR_DB_BUILD_DEPENDS=	${PEARDIR}/DB.php:databases/pear-DB
PEAR_SOAP_BUILD_DEPENDS=${PEARDIR}/SOAP/Base.php:net/pear-SOAP
PEAR_XML_SERIALIZER_BUILD_DEPENDS=	${PEARDIR}/XML/Serializer.php:devel/pear-XML_Serializer

.include <bsd.port.mk>
