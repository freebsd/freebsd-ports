# New ports collection makefile for:	mod_sequester
# Date created:				10 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	mod_sequester
PORTVERSION=	1.7.0
CATEGORIES=	www
MASTER_SITES=	http://MeepZor.Com/packages/mod_sequester/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13

WRKSRC=		${WRKDIR}/mod_sequester
APXS?=		${LOCALBASE}/sbin/apxs

do-build:
	@cd ${WRKSRC} && ${APXS} -c ${PORTNAME}.c

do-install:
	${APXS} -i -A -n ${PORTNAME:S/_//g} ${WRKSRC}/${PORTNAME}.so

.include <bsd.port.mk>
