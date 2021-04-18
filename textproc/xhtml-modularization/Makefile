# Created by: nectar

PORTNAME=	xhtml-modularization
PORTVERSION=	1.0.${RECDATE}
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.w3.org/TR/2001/REC-${PORTNAME}-${RECDATE}/
DISTNAME=	${PORTNAME}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	W3C's Modularization of XHTML DTDs and docs

RUN_DEPENDS=	xmlcatmgr:textproc/xmlcatmgr

USES=		tar:tgz

NO_ARCH=	yes
NO_BUILD=	yes
NO_MTREE=	yes

SUB_FILES=	catalog.xml
WRKSRC=		${WRKDIR}/${PORTNAME}-${RECDATE}

RECDATE=	20010410

OPTIONS_DEFINE=	DOCS EXAMPLES

.include "${.CURDIR}/contents.inc"

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/xml/dtd/xhtml-modularization
.for f in ${contents_DTD}
	${INSTALL_DATA} ${WRKSRC}/DTD/${f} ${STAGEDIR}${PREFIX}/share/xml/dtd/xhtml-modularization/${f}
.endfor
	${INSTALL_DATA} ${WRKDIR}/catalog.xml ${STAGEDIR}${PREFIX}/share/xml/dtd/xhtml-modularization/catalog.xml

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/images
.for f in ${contents_DOC}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/${f}
.endfor

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${contents_EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/DTD/examples/${f} ${STAGEDIR}${EXAMPLESDIR}/${f}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/templates
.for f in ${contents_TEMPLATES}
	${INSTALL_DATA} ${WRKSRC}/DTD/templates/${f} ${STAGEDIR}${EXAMPLESDIR}/templates/${f}
.endfor

.include <bsd.port.mk>
