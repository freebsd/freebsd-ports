# New ports collection makefile for:	mod_geoip2
# Date created:				26 Aug 2005
# Whom:					Jukka A. Ukkonen <jau@iki.fi>
#
# $FreeBSD$
#

PORTNAME=	mod_geoip2
PORTVERSION=	1.1.7
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.maxmind.com/download/geoip/api/mod_geoip2/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	jau@iki.fi
COMMENT=	An Apache module that provides the country code of the client's IP

LIB_DEPENDS=	GeoIP.5:${PORTSDIR}/net/GeoIP

CONFLICTS=	mod_geoip-[0-9]*

USE_APACHE=	yes
WITH_APACHE2=	yes

SUB_FILES=	pkg-message
PORTDOCS=	Changes INSTALL README README.php

do-build:
	@cd ${WRKSRC} && \
	${APXS} -c -L${LOCALBASE}/lib -I${LOCALBASE}/include -lGeoIP mod_geoip.c

do-install:
	${APXS} -i -A -n geoip ${WRKSRC}/.libs/mod_geoip.so
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
