# New ports collection makefile for:	mod_geoip
# Date created:			24 Jan 2003
# Whom:				Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_geoip
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.maxmind.com/download/geoip/api/mod_geoip/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	An Apache module that provides the country code of the client's IP

LIB_DEPENDS=	GeoIP.4:${PORTSDIR}/net/GeoIP

USE_APACHE=	yes

.include <bsd.port.pre.mk>

PORTDOCS=		Changes INSTALL README README.php

do-build:
	@cd ${WRKSRC} && \
	${APXS} -c -L${LOCALBASE}/lib -I${LOCALBASE}/include -lGeoIP mod_geoip.c

do-install:
	${APXS} -i -A -n geoip ${WRKSRC}/mod_geoip.so
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mod_geoip
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/mod_geoip/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
