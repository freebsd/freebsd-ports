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
COMMENT=	Apache module to supply access control based on ident reply

USE_APACHE=	yes
WRKSRC=		${WRKDIR}/mod_access_identd

do-build:
	@cd ${WRKSRC} && ${APXS} -c ${PORTNAME}.c

do-install:
	${APXS} -i -A -n ${PORTNAME:S/_//g} ${WRKSRC}/${PORTNAME}.so

.include <bsd.port.mk>
