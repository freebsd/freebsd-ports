# New ports collection makefile for:	mod_geoip2
# Date created:				26 Aug 2005
# Whom:					Jukka A. Ukkonen <jau@iki.fi>
#
# $FreeBSD$
#

PORTNAME=	mod_geoip2
PORTVERSION=	1.2.5
CATEGORIES=	www geography
MASTER_SITES=	http://www.maxmind.com/download/geoip/api/mod_geoip2/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	jau@iki.fi
COMMENT=	An Apache module that provides the country code of the client's IP

BUILD_DEPENDS=	GeoIP>=1.4.4:${PORTSDIR}/net/GeoIP
RUN_DEPENDS=	GeoIP>=1.4.4:${PORTSDIR}/net/GeoIP

MAKE_JOBS_SAFE=  yes

CONFLICTS=	mod_geoip-[0-9]*

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}

USE_APACHE=	2.0+
MODULENAME=	mod_geoip
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
AP_INC+=	${LOCALBASE}/include
AP_LIB+=	${LOCALBASE}/lib -lGeoIP

SUB_FILES+=	pkg-message
PORTDOCS=	Changes INSTALL README README.php

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
