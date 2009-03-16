# Ports collection makefile for:  pear-Services_Weather
# Date created:			  04 April 2004
# Whom:				  Thierry Thomas (<thierry@FreeBSD.org>)
#
# $FreeBSD$
#

PORTNAME=	Services_Weather
PORTVERSION=	1.4.4
CATEGORIES=	misc www pear geography

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR interface to various online weather-services

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS} \
		${PEARDIR}/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request

USE_PHP=	ctype pcre

LATEST_LINK=	pear-Services_Weather
OPTIONS=	PEAR_NET_FTP "PEAR::Net::FTP support" off \
		PEAR_CACHE "PEAR::Cache support" off \
		PEAR_DB "PEAR::DB support" off \
		PEAR_SOAP "PEAR::SOAP support" off \
		PEAR_XML_SERIALIZER "PEAR::XML::Serializer support" off

CATEGORY=	Services
FILES=		Weather.php Weather/Common.php Weather/Ejse.php			\
		Weather/Globalweather.php Weather/Metar.php 			\
		Weather/Weatherdotcom.php buildMetarDB.php images/sunrise.gif 	\
		images/sunset.gif
EXAMPLES=	ejse-basic.php globalweather-basic.php metar-basic.php 		\
		metar-extensive.php weather.com-basic.php weather.com-extensive.php

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_NET_FTP)
BUILD_DEPENDS+=	${PEARDIR}/Net/FTP.php:${PORTSDIR}/ftp/pear-Net_FTP
.endif

.if defined(WITH_PEAR_CACHE)
BUILD_DEPENDS+=	${PEARDIR}/Cache.php:${PORTSDIR}/sysutils/pear-Cache
.endif

.if defined(WITH_PEAR_DB)
BUILD_DEPENDS+=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
.endif

.if defined(WITH_PEAR_SOAP)
BUILD_DEPENDS+=	${PEARDIR}/SOAP/Base.php:${PORTSDIR}/net/pear-SOAP
.endif

.if defined(WITH_PEAR_XML_SERIALIZER)
BUILD_DEPENDS+=	${PEARDIR}/XML/Serializer.php:${PORTSDIR}/devel/pear-XML_Serializer
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
