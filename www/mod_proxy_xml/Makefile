# New ports collection Makefile for:	mod_proxy_xml
#
# Date created:		10/01/2007
# Whom:			Dominic Marks <dom@goodforbusiness.co.uk>
#
# $FreeBSD$
#

PORTNAME=	mod_proxy_xml
PORTVERSION=	0.1
CATEGORIES=	www
MASTER_SITES=	http://apache.webthing.com/svn/apache/filters/xmlns/
DISTFILES=	xmlns.h mod_proxy_xml.c

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apache module for rewriting URI references in XML

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
	@${CP} ${DISTDIR}/xmlns.h ${DISTDIR}/mod_proxy_xml.c ${WRKDIR}

do-build:
	@(cd ${WRKDIR} && ${APXS} -c -I ${XML2_INC} -L ${XML2_LIB} -lxml2 mod_proxy_xml.c)

do-install:
	@(cd ${WRKDIR} && ${APXS} -A -i mod_proxy_xml.la)

.include <bsd.port.mk>
