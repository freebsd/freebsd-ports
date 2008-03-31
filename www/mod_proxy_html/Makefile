# New ports collection makefile for:	mod_proxy_html
# Date created:		2004-07-29
# Whom:			David Lay <dsl@webize.com.au>
#
# $FreeBSD$
#

PORTNAME=	mod_proxy_html
PORTVERSION=	3.0.0
CATEGORIES=	www
MASTER_SITES=	http://apache.webthing.com/${PORTNAME}/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	dsl@bitwizards.com.au
COMMENT=	Apache module for rewriting HTML links in proxied content

SUB_FILES=	pkg-message
USE_GNOME=	libxml2
USE_APACHE?=2.2
NO_WRKSUBDIR=	yes

XML2_INC=	${LOCALBASE}/include/libxml2
XML2_LIB=	${LOCALBASE}/lib

do-build:
	@(cd ${WRKDIR}/${PORTNAME} && ${APXS} -c -I ${XML2_INC} -L ${XML2_LIB} -lxml2 ${PORTNAME}.c)

do-install:
	@(cd ${WRKDIR}/${PORTNAME} && ${APXS} -A -i ${PORTNAME}.la)

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
