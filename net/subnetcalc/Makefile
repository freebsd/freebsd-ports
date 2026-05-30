PORTNAME=	subnetcalc
DISTVERSION=	2.7.1
CATEGORIES=	net
MASTER_SITES=	https://www.nntb.no/~dreibh/subnetcalc/download/

MAINTAINER=	thomas.dreibholz@gmail.com
COMMENT=	IPv4/IPv6 Subnet Calculator
WWW=		https://www.nntb.no/~dreibh/subnetcalc/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libidn2.so:dns/libidn2

USES=		cmake tar:xz

OPTIONS_DEFINE=		GEOIP NLS
OPTIONS_DEFAULT=	GEOIP
OPTIONS_SUB=		yes

GEOIP_DESC=		Build with GeoIP support

GEOIP_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb
GEOIP_CMAKE_BOOL=	WITH_GEOIP

NLS_USES=		gettext
NLS_CMAKE_BOOL=		WITH_I18N

.include <bsd.port.mk>
