# New ports collection makefile for:	mod_xml2enc
# Date created:				02 March 2011
# Whom:					Marin Atanasov Nikolov <dnaeon@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mod_xml2enc
PORTVERSION=	1.0.3
CATEGORIES=	www
MASTER_SITES=	http://apache.webthing.com/mod_proxy_html/
DISTNAME=	mod_proxy_html
DIST_SUBDIR=	mod_proxy_html

MAINTAINER=	dnaeon@gmail.com
COMMENT=	Apache module for converting encoding before and/or after a filter run

MAKE_JOBS_SAFE=	yes

USE_APACHE=	2.2+
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
SHORTMODNAME=	xml2enc
USE_BZIP2=	YES
USE_GNOME=	libxml2

AP_INC+=	${LOCALBASE}/include/libxml2 -I${WRKSRC}
AP_LIB+=	${LOCALBASE}/lib
AP_EXTRAS+=	-lxml2

PLIST_FILES=	%%DOCSDIR%%/COPYING
PLIST_DIRS=	%%DOCSDIR%%

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/COPYING ${DOCSDIR}

.include <bsd.port.mk>
