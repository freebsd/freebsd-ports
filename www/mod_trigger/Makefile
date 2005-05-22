# New ports collection makefile for:	mod_trigger
# Date created:				10 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	mod_trigger
PORTVERSION=	1.1
CATEGORIES=	www
MASTER_SITES=	http://download.tangent.org/

MAINTAINER=	svenasse@polaris.ca
COMMENT=	Apache module to launch triggers if certain actions occur

USE_APACHE=	yes

do-build:
	@cd ${WRKSRC} && ${APXS} -c ${PORTNAME}.c

do-install:
	${APXS} -i -A -n ${PORTNAME:S/_//g} ${WRKSRC}/${PORTNAME}.so

.include <bsd.port.mk>
