# New ports collection makefile for:	mod_access_identd
# Date created:				10 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	mod_access_identd
PORTVERSION=	1.2.0
CATEGORIES=	www
MASTER_SITES=	http://MeepZor.Com/packages/mod_access_identd/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${APXS}:${APACHE_PORT}
RUN_DEPENDS=	${APXS}:${APACHE_PORT}

WRKSRC=		${WRKDIR}/mod_access_identd
APXS?=		${LOCALBASE}/sbin/apxs
APACHE_PORT?=	${PORTSDIR}/www/apache13

do-build:
	@cd ${WRKSRC} && ${APXS} -c ${PORTNAME}.c

do-install:
	${APXS} -i -A -n ${PORTNAME:S/_//g} ${WRKSRC}/${PORTNAME}.so

.include <bsd.port.mk>
