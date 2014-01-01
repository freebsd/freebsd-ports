# Created by: Jukka A. Ukkonen <jau@iki.fi>
# $FreeBSD$

PORTNAME=	mod_geoip2
PORTVERSION=	1.2.8
CATEGORIES=	www geography
MASTER_SITES=	http://geolite.maxmind.com/download/geoip/api/mod_geoip2/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	jau@iki.fi
COMMENT=	Apache module that provides the country code of the client IP

LICENSE=	APACHE20

BUILD_DEPENDS=	GeoIP>=1.4.4:${PORTSDIR}/net/GeoIP
RUN_DEPENDS=	GeoIP>=1.4.4:${PORTSDIR}/net/GeoIP

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}

USE_APACHE=	22
MODULENAME=	mod_geoip
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
AP_INC+=	${LOCALBASE}/include
AP_LIB+=	${LOCALBASE}/lib -lGeoIP

SUB_FILES+=	pkg-message
PORTDOCS=	Changes INSTALL README README.php

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
