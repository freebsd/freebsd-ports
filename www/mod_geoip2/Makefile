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

DEPRECATED=     Uses legacy GeoIP 1 format which no longer works; switch to GeoIP 2 where possible
EXPIRATION_DATE=2019-02-15

USE_GITHUB=	yes
GH_ACCOUNT=	maxmind
GH_PROJECT=	geoip-api-mod_geoip2
USES=		apache:2.2+
MODULENAME=	mod_geoip
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
AP_INC+=	${LOCALBASE}/include
AP_LIB+=	${LOCALBASE}/lib -lGeoIP

SUB_FILES+=	pkg-message
PORTDOCS=	Changes INSTALL.md README.md README.php

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
