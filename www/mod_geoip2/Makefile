# Created by: Jukka A. Ukkonen <jau@iki.fi>
# $FreeBSD$

PORTNAME=	mod_geoip2
PORTVERSION=	1.2.10
CATEGORIES=	www geography

MAINTAINER=	jau@iki.fi
COMMENT=	Apache module that provides the country code of the client IP

LICENSE=	APACHE20

BUILD_DEPENDS=	GeoIP>=1.4.4:net/GeoIP
RUN_DEPENDS=	GeoIP>=1.4.4:net/GeoIP

USE_GITHUB=	yes
GH_ACCOUNT=	maxmind
GH_PROJECT=	geoip-api-mod_geoip2
USE_APACHE=	22+
MODULENAME=	mod_geoip
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
AP_INC+=	${LOCALBASE}/include
AP_LIB+=	${LOCALBASE}/lib -lGeoIP

SUB_FILES+=	pkg-message
PORTDOCS=	Changes INSTALL.md README.md README.php

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
