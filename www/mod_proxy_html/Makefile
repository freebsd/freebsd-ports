# New ports collection makefile for:	mod_proxy_html
# Date created:		2004-07-29
# Whom:			David Lay <dsl@webize.com.au>
#
# $FreeBSD$
#

PORTNAME=	mod_proxy_html
PORTVERSION=	3.1.2
CATEGORIES=	www
MASTER_SITES=	http://apache.webthing.com/${PORTNAME}/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module for rewriting HTML links in proxied content

MAKE_JOBS_SAFE=	yes

SUB_FILES=	pkg-message
USE_APACHE=	2.0+
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
SHORTMODNAME=	proxy_html
USE_BZIP2=	YES
USE_GNOME=	libxml2

AP_INC+=	${LOCALBASE}/include/libxml2 -I${WRKSRC}
AP_LIB+=	${LOCALBASE}/lib
AP_EXTRAS+=	-lxml2

PLIST_FILES=	%%DOCSDIR%%/COPYING %%DOCSDIR%%/README \
		%%DOCSDIR%%/proxy_html.conf
PLIST_DIRS=	%%DOCSDIR%%

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/COPYING ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/proxy_html.conf ${DOCSDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
