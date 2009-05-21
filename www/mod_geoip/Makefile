# New ports collection makefile for:	mod_geoip
# Date created:			24 Jan 2003
# Whom:				Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_geoip
PORTVERSION=	1.3.4
PORTREVISION=	1
CATEGORIES=	www geography
MASTER_SITES=	http://www.maxmind.com/download/geoip/api/mod_geoip/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	yarodin@gmail.com
COMMENT=	An Apache module that provides the country code of the client's IP

BUILD_DEPENDS=	GeoIP>=1.4.4:${PORTSDIR}/net/GeoIP
RUN_DEPENDS=	GeoIP>=1.4.4:${PORTSDIR}/net/GeoIP

MAKE_JOBS_SAFE=  yes

CONFLICTS=	mod_geoip2-[0-9]*

USE_APACHE=	1.3
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
