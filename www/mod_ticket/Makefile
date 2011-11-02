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

DEPRECATED=	apache13 is deprecated, migrate to 2.2.x+ now
EXPIRATION_DATE=	2012-01-01

MAKE_JOBS_SAFE=  yes

CONFLICTS=	apache-contrib-1.*

USE_APACHE=	13
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

do-extract:
	${MKDIR} ${WRKSRC}/
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}/

.include <bsd.port.mk>
