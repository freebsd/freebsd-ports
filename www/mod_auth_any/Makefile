# New ports collection makefile for:	mod_auth_any
# Date created:				10 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	mod_auth_any
PORTVERSION=	1.3.2
CATEGORIES=	www
MASTER_SITES=	http://www.itlab.musc.edu/webNIS/dist/

MAINTAINER=	sheepkiller@cultdeadsheep.org
COMMENT=	Apache module to use any command line program to authenticate a user

BUILD_DEPENDS=	${APXS}:${APACHE_PORT}
RUN_DEPENDS=	${APXS}:${APACHE_PORT}

WRKSRC=		${WRKDIR}/${PORTNAME}

APXS?=		${LOCALBASE}/sbin/apxs
APACHE_PORT?=	${PORTSDIR}/www/apache13

do-build:
	@cd ${WRKSRC}/src && ${APXS} -c ${PORTNAME}.c

do-install:
	${APXS} -i -A -n ${PORTNAME:S/mod_//g} ${WRKSRC}/src/${PORTNAME}.so

.include <bsd.port.mk>
