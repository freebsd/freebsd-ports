# Created by: JunSeon Oh <hollywar@mail.holywar.net>
# $FreeBSD$

PORTNAME=	mod_fastcgi
PORTVERSION=	2.4.7.1
CATEGORIES=	www
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache 2.4 fast-cgi module

USES=		apache:2.4+

USE_GITHUB=	yes
GH_ACCOUNT=	FastCGI-Archives

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
SRC_FILE=	*.c
PORTDOCS=	mod_fastcgi.html

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
