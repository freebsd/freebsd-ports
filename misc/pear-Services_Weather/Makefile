# Created by: Thierry Thomas (<thierry@FreeBSD.org>)

PORTNAME=	Services_Weather
PORTVERSION=	1.4.7
PORTEPOCH=	1
CATEGORIES=	misc www pear geography

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PEAR interface to various online weather-services

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}HTTP_Request>=1.2.0:www/pear-HTTP_Request@${PHP_FLAVOR}

USES=		pear
USE_PHP=	ctype pcre

NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	pear

OPTIONS_DEFINE=	CACHE DB NET_FTP SOAP XML_SERIALIZER
NET_FTP_DESC=	PEAR::Net::FTP support
CACHE_DESC=	PEAR::Cache support
DB_DESC=	PEAR::DB support
SOAP_DESC=	PEAR::SOAP support
XML_SERIALIZER_DESC=	PEAR::XML::Serializer support

CACHE_RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}Cache>=1.5.3:sysutils/pear-Cache@${PHP_FLAVOR}
DB_RUN_DEPENDS=		${PEAR_PKGNAMEPREFIX}DB>=1.4.0:databases/pear-DB@${PHP_FLAVOR}
NET_FTP_RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}Net_FTP>=1.3.1:ftp/pear-Net_FTP@${PHP_FLAVOR}
SOAP_RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}SOAP>=0.7.5:net/pear-SOAP@${PHP_FLAVOR}
XML_SERIALIZER_RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}XML_Serializer>=0.8:devel/pear-XML_Serializer@${PHP_FLAVOR}

.include <bsd.port.mk>
