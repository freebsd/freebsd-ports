# New ports collection makefile for:	mod_proxy_html
# Date created:		2004-07-29
# Whom:			David Lay <dsl@webize.com.au>
#
# $FreeBSD$
#

PORTNAME=	mod_proxy_html
PORTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://apache.webthing.com/${PORTNAME}/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	dsl@bitwizards.com.au
COMMENT=	Apache module for rewriting HTML links in proxied content

SUB_FILES=	pkg-message
USE_APACHE=	2.0+
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
SHORTMODNAME=	proxy_html
USE_GNOME=	libxml2

AP_INC+=	${LOCALBASE}/include/libxml2
AP_LIB+=	${LOCALBASE}/lib
AP_EXTRAS+=	-lxml2

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
