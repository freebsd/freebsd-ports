# New ports collection makefile for:	mod_ticket
# Date created:				10 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	mod_ticket
PORTVERSION=	1.0
CATEGORIES=	www
MASTER_SITES=	http://germ.semiotek.com/ticket/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.c

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Apache module for a digitally signed ticket in URL

BUILD_DEPENDS=	${APXS}:${APACHE_PORT}
RUN_DEPENDS=	${APXS}:${APACHE_PORT}

APXS?=		${LOCALBASE}/sbin/apxs
APACHE_PORT?=	${PORTSDIR}/www/apache13

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-build:
	@cd ${WRKSRC} && ${APXS} -c ${PORTNAME}.c

do-install:
	${APXS} -i -A -n ${PORTNAME:S/_//g} ${WRKSRC}/${PORTNAME}.so

.include <bsd.port.mk>
