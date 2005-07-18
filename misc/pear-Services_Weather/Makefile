# Ports collection makefile for:  pear-Services_Weather
# Date created:			  04 April 2004
# Whom:				  Thierry Thomas (<thierry@FreeBSD.org>)
#
# $FreeBSD$
#

PORTNAME=	Services_Weather
PORTVERSION=	1.3.2
CATEGORIES=	misc www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR interface to various online weather-services

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

.if !defined (WITHOUT_CACHE)
BUILD_DEPENDS+=	${PEARDIR}/Cache/Cache.php:${PORTSDIR}/sysutils/pear-Cache
.endif
.if !defined (WITHOUT_DB)
BUILD_DEPENDS+=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
.endif
.if !defined (WITHOUT_HTTPR)
BUILD_DEPENDS+=	${PEARDIR}/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request
.endif
.if !defined (WITHOUT_SERIALIZER)
BUILD_DEPENDS+=	${PEARDIR}/XML/Serializer.php:${PORTSDIR}/devel/pear-XML_Serializer
.endif
.if !defined (WITHOUT_SOAP)
BUILD_DEPENDS+=	${PEARDIR}/SOAP/Base.php:${PORTSDIR}/net/pear-SOAP
.endif

CATEGORY=	Services
FILES=		Weather.php Weather/Common.php Weather/Globalweather.php	\
		Weather/Ejse.php Weather/Metar.php Weather/Weatherdotcom.php	\
		buildMetarDB.php images/sunrise.gif images/sunset.gif
EXAMPLES=	globalweather-basic.php ejse-basic.php metar-basic.php		\
		metar-extensive.php php_sunrise_sunset.php weather.com-basic.php\
		weather.com-extensive.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
