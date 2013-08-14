# Created by: Dominic Marks <dom@goodforbusiness.co.uk>
# $FreeBSD$

PORTNAME=	mod_xmlns
PORTVERSION=	0.97
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://apache.webthing.com/svn/apache/filters/xmlns/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DISTFILES=	xmlns.h mod_xmlns.c

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module for XML namespaces


USE_GNOME=	libxml2
USE_APACHE=	22+

XML2_INC=	${LOCALBASE}/include/libxml2
XML2_LIB=	${LOCALBASE}/lib

pre-extract:
	@${MKDIR} ${WRKDIR}

do-extract:
	@${CP} ${DISTDIR}/xmlns.h ${DISTDIR}/mod_xmlns.c ${WRKDIR}

do-build:
	@(cd ${WRKDIR} && ${APXS} -c -I ${XML2_INC} -L ${XML2_LIB} -lxml2 mod_xmlns.c)

do-install:
	@(cd ${WRKDIR} && ${APXS} -A -i mod_xmlns.la)

.include <bsd.port.mk>
