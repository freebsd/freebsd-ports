PORTNAME=	Horde_Service_Weather
PORTVERSION=	2.5.5
CATEGORIES=	www pear

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Weather Provider

USES=	horde cpe
USE_HORDE_BUILD=	Horde_Role
USE_HORDE_RUN=	Horde_Role \
		Horde_Date \
		Horde_Exception \
		Horde_Http \
		Horde_Translation \
		Horde_Url

CONFLICTS_INSTALL=	php*-pear-horde-Horde_Service_Weather # bin/horde-service-weather-metar-database

.include <bsd.port.mk>
