# New ports collection makefile for:	mod_cgi_debug
# Date created:				10 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	mod_cgi_debug
PORTVERSION=	0.7
CATEGORIES=	www
MASTER_SITES=	http://download.tangent.org/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module to make debugging server-side scripts easier

USE_APACHE=	yes

do-build:
	@cd ${WRKSRC} && ${APXS} -c ${PORTNAME}.c

do-install:
	${APXS} -i -A -n ${PORTNAME:S/_//g} ${WRKSRC}/${PORTNAME}.so

.include <bsd.port.mk>
