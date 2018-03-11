# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_uid
PORTVERSION=	1.1.0
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.lexa.ru/pub/apache-rus/contrib/

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Apache module issuing the "correct" cookies for counting the site visitors

LICENSE=	APACHE20

USES=		apache:2.2
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
MODULENAME=	mod_uid2

PORTDOCS=	README.html

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
