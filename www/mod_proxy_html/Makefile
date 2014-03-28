# Created by: David Lay <dsl@webize.com.au>
# $FreeBSD$

PORTNAME=	mod_proxy_html
PORTVERSION=	3.1.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://apache.webthing.com/${PORTNAME}/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	mod_proxy_html

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module for rewriting HTML links in proxied content

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/${APACHEMODDIR}/mod_xml2enc.so:${PORTSDIR}/www/mod_xml2enc

SUB_FILES=	pkg-message
USE_APACHE=	22
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
SHORTMODNAME=	proxy_html
USES=		tar:bzip2
USE_GNOME=	libxml2

AP_INC+=	${LOCALBASE}/include/libxml2 -I${WRKSRC}
AP_LIB+=	${LOCALBASE}/lib
AP_EXTRAS+=	-lxml2

PORTDOCS=	README proxy_html.conf

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
