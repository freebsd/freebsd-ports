# New ports collection makefile for:	mod_geoip
# Date created:			24 Jan 2003
# Whom:				Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_geoip
PORTVERSION=	1.1.1
CATEGORIES=	www
MASTER_SITES=	http://www.maxmind.com/download/geoip/api/mod_geoip/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	seanc@FreeBSD.org

BUILD_DEPENDS=	${APXS}:${APACHE_PORT}
RUN_DEPENDS=	${APXS}:${APACHE_PORT}

APXS?=		${LOCALBASE}/sbin/apxs
APACHE_PORT?=	${PORTSDIR}/www/apache13

DOCS=		Changes INSTALL README README.php

do-build:
	@cd ${WRKSRC} && \
	${APXS} -c -L${LOCALBASE}/lib -I${LOCALBASE}/include mod_geoip.c

do-install:
	${APXS} -i -A -n geoip ${WRKSRC}/mod_geoip.so
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mod_geoip
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/mod_geoip/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
