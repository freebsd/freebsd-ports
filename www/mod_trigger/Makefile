# New ports collection makefile for:	mod_trigger
# Date created:				10 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	mod_trigger
PORTVERSION=	1.0
CATEGORIES=	www
MASTER_SITES=	http://www.tangent.org/mod_trigger/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13

APXS?=		${LOCALBASE}/sbin/apxs

do-build:
	@cd ${WRKSRC} && ${APXS} -c ${PORTNAME}.c

do-install:
	${APXS} -i -A -n ${PORTNAME:S/_//g} ${WRKSRC}/${PORTNAME}.so

.include <bsd.port.mk>
