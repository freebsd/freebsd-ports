# New ports collection Makefile for:	mod_line_edit
#
# Date created:		10/01/2007
# Whom:			Dominic Marks <dom@goodforbusiness.co.uk>
#
# $FreeBSD$
#

PORTNAME=	mod_line_edit
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://apache.webthing.com/mod_line_edit/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DISTFILES=	mod_line_edit.c

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module for simple text rewriting

MAKE_JOBS_SAFE=  yes

USE_APACHE=	2.2+

do-extract:
	@${DO_NADA}

pre-fetch:
	@${MKDIR} ${WRKDIR}

post-fetch:
	@${CP} ${DISTDIR}/mod_line_edit.c ${WRKDIR}

do-build:
	@(cd ${WRKDIR} && ${APXS} -c mod_line_edit.c)

do-install:
	@(cd ${WRKDIR} && ${APXS} -A -i mod_line_edit.la)

.include <bsd.port.mk>
