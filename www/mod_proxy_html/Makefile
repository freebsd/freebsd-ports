# New ports collection makefile for:	mod_proxy_html
# Date created:		2004-07-29
# Whom:			David Lay <dsl@webize.com.au>
#
# $FreeBSD$
#

PORTNAME=	mod_proxy_html
PORTVERSION=	2.2
CATEGORIES=	www
MASTER_SITES=	http://apache.webthing.com/${PORTNAME}/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.c

MAINTAINER=	dsl@webize.com.au
COMMENT=	Apache module for rewriting HTML links in proxied content

USE_GNOME=	libxml2
USE_APACHE=	yes
WITH_APACHE2=	yes
NO_WRKSUBDIR=	yes

XML2_INC=	${LOCALBASE}/include/libxml2
XML2_LIB=	${LOCALBASE}/lib

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} -p ${DISTDIR}/${DISTFILES} ${WRKDIR}/${PORTNAME}.c

do-build:
	@(cd ${WRKSRC} && ${APXS} -c -I ${XML2_INC} -L ${XML2_LIB} -lxml2 ${PORTNAME}.c)

do-install:
	@(cd ${WRKSRC} && ${APXS} -A -i ${PORTNAME}.la)

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
