# Created by: Hiroki Sato <hrs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xmlformat
PORTVERSION=	1.04
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.kitebird.com/software/xmlformat/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	An XML Document Formatter

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_BUILD=	yes
USES=		perl5 shebangfix

SHEBANG_FILES=	${WRKSRC}/xmlformat.pl
PLIST_FILES=	bin/xmlformat
PORTDOCS_root=	BUGS ChangeLog INSTALL LICENSE README TODO
PORTDOCS_docs=	docs/API docs/catalog.xml \
		docs/tutorial.html docs/tutorial.pdf docs/tutorial.xml \
		docs/xmlformat.conf docs/xmlformat.html docs/xmlformat.pdf \
		docs/xmlformat.xml
PORTDOCS=	${PORTDOCS_root} ${PORTDOCS_docs:S,^docs/,,}
PORTEXAMPLES=	doc1.xml doc2.conf1 doc2.conf2 doc2.conf3 \
		doc2.conf4 doc2.xml

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xmlformat.pl \
	    ${STAGEDIR}${PREFIX}/bin/xmlformat
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && \
	    ${INSTALL_DATA} ${PORTDOCS_root} ${PORTDOCS_docs} \
	    ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/docs/examples && \
	    ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
