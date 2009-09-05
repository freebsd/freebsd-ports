# New ports collection Makefile for:	mod_xmlns
#
# Date created:		10/01/2007
# Whom:			Dominic Marks <dom@goodforbusiness.co.uk>
#
# $FreeBSD$
#

PORTNAME=	mod_xmlns
PORTVERSION=	0.97
CATEGORIES=	www
MASTER_SITES=	http://apache.webthing.com/svn/apache/filters/xmlns/
DISTFILES=	xmlns.h mod_xmlns.c

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module for XML namespaces

MAKE_JOBS_SAFE=  yes

USE_GNOME=	libxml2
USE_APACHE=	2.0+

XML2_INC=	${LOCALBASE}/include/libxml2
XML2_LIB=	${LOCALBASE}/lib

do-extract:
	@${DO_NADA}

pre-fetch:
	@${MKDIR} ${WRKDIR}

post-fetch:
	@${CP} ${DISTDIR}/xmlns.h ${DISTDIR}/mod_xmlns.c ${WRKDIR}

do-build:
	@(cd ${WRKDIR} && ${APXS} -c -I ${XML2_INC} -L ${XML2_LIB} -lxml2 mod_xmlns.c)

do-install:
	@(cd ${WRKDIR} && ${APXS} -A -i mod_xmlns.la)

.include <bsd.port.mk>
