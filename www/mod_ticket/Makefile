# New ports collection makefile for:	mod_ticket
# Date created:				10 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	mod_ticket
PORTVERSION=	1.0
CATEGORIES=	www
# mastersite disappeared in March 2003, no replacement found
MASTER_SITES=	# http://germ.semiotek.com/ticket/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.c

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module for a digitally signed ticket in URL

USE_APACHE=	yes

CONFLICTS=	apache-contrib-1.*

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-build:
	@cd ${WRKSRC} && ${APXS} -c ${PORTNAME}.c

do-install:
	${APXS} -i -A -n ${PORTNAME:S/_//g} ${WRKSRC}/${PORTNAME}.so

.include <bsd.port.mk>
