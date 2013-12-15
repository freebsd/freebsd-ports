# Created by: Marin Atanasov Nikolov <dnaeon@gmail.com>
# $FreeBSD$

PORTNAME=	mod_xml2enc
PORTVERSION=	1.0.3
CATEGORIES=	www
MASTER_SITES=	http://apache.webthing.com/mod_proxy_html/
DISTNAME=	mod_proxy_html
DIST_SUBDIR=	mod_proxy_html

MAINTAINER=	dnaeon@gmail.com
COMMENT=	Apache module for converting encoding before and/or after a filter run

LICENSE=	GPLv2

# included in apache24
# http://httpd.apache.org/docs/2.4/mod/mod_xml2enc.html
USE_APACHE=	22
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
SHORTMODNAME=	xml2enc
USE_BZIP2=	yes
USE_GNOME=	libxml2

AP_INC+=	${LOCALBASE}/include/libxml2 -I${WRKSRC}
AP_LIB+=	${LOCALBASE}/lib
AP_EXTRAS+=	-lxml2

PORTDOCS=	COPYING

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/COPYING ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
