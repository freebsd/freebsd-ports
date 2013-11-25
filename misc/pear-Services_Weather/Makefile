# Created by: Thierry Thomas (<thierry@FreeBSD.org>)
# $FreeBSD$

PORTNAME=	Services_Weather
PORTVERSION=	1.4.6
PORTEPOCH=	1
CATEGORIES=	misc www pear geography

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR interface to various online weather-services

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS:=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request

USE_PHP=	ctype pcre

LATEST_LINK=	pear-Services_Weather
OPTIONS_DEFINE=	PEAR_NET_FTP PEAR_CACHE PEAR_DB PEAR_SOAP PEAR_XML_SERIALIZER
PEAR_NET_FTP_DESC=	PEAR::Net::FTP support
PEAR_CACHE_DESC=	PEAR::Cache support
PEAR_DB_DESC=	PEAR::DB support
PEAR_SOAP_DESC=	PEAR::SOAP support
PEAR_XML_SERIALIZER_DESC=	PEAR::XML::Serializer support

PEAR_AUTOINSTALL=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPEAR_NET_FTP}
BUILD_DEPENDS+=	${PEARDIR}/Net/FTP.php:${PORTSDIR}/ftp/pear-Net_FTP
.endif

.if ${PORT_OPTIONS:MPEAR_CACHE}
BUILD_DEPENDS+=	${PEARDIR}/Cache.php:${PORTSDIR}/sysutils/pear-Cache
.endif

.if ${PORT_OPTIONS:MPEAR_DB}
BUILD_DEPENDS+=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
.endif

.if ${PORT_OPTIONS:MPEAR_SOAP}
BUILD_DEPENDS+=	${PEARDIR}/SOAP/Base.php:${PORTSDIR}/net/pear-SOAP
.endif

.if ${PORT_OPTIONS:MPEAR_XML_SERIALIZER}
BUILD_DEPENDS+=	${PEARDIR}/XML/Serializer.php:${PORTSDIR}/devel/pear-XML_Serializer
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.mk>
