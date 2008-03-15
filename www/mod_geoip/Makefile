# New ports collection makefile for:	mod_geoip
# Date created:			24 Jan 2003
# Whom:				Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_geoip
PORTVERSION=	1.3.0
CATEGORIES=	www geography
MASTER_SITES=	http://www.maxmind.com/download/geoip/api/mod_geoip/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Apache module that provides the country code of the client's IP

BUILD_DEPENDS=	GeoIP>=1.4.4:${PORTSDIR}/net/GeoIP
RUN_DEPENDS=	GeoIP>=1.4.4:${PORTSDIR}/net/GeoIP

USE_APACHE=	1.3
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

.include <bsd.port.pre.mk>

PORTDOCS=		Changes INSTALL README README.php

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mod_geoip
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/mod_geoip/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
