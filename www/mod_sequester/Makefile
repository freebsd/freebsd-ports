# New ports collection makefile for:	mod_sequester
# Date created:				10 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	mod_sequester
PORTVERSION=	1.8
CATEGORIES=	www
MASTER_SITES=	http://MeepZor.Com/packages/mod_sequester/
DISTNAME=	${PORTNAME}-1.7.0

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module that controls access to the website using secure info

USE_APACHE=	yes
WRKSRC=		${WRKDIR}/mod_sequester

do-build:
	@cd ${WRKSRC} && ${APXS} -c ${PORTNAME}.c

do-install:
	${APXS} -i -A -n ${PORTNAME:S/_//g} ${WRKSRC}/${PORTNAME}.so

.include <bsd.port.mk>
