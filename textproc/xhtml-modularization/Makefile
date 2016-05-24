# Created by: nectar
# $FreeBSD$

PORTNAME=	xhtml-modularization
PORTVERSION=	1.0.${RECDATE}
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.w3.org/TR/2001/REC-${PORTNAME}-${RECDATE}/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	W3C's Modularization of XHTML DTDs and docs

RUN_DEPENDS=	xmlcatmgr:textproc/xmlcatmgr

USES=		tar:tgz

RECDATE=	20010410

OPTIONS_DEFINE=	DOCS EXAMPLES

SUB_FILES=	catalog.xml
NO_MTREE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${RECDATE}

dir_DTD=	share/xml/dtd/xhtml-modularization

.include "${.CURDIR}/contents.inc"

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${dir_DTD}
.for f in ${contents_DTD}
	${INSTALL_DATA} ${WRKSRC}/DTD/${f} ${STAGEDIR}${PREFIX}/${dir_DTD}/${f}
.endfor
	${INSTALL_DATA} ${WRKDIR}/catalog.xml ${STAGEDIR}${PREFIX}/${dir_DTD}/catalog.xml

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/images
.for f in ${contents_DOC}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/${f}
.endfor

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${contents_EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/DTD/examples/${f} \
	    ${STAGEDIR}${EXAMPLESDIR}/${f}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/templates
.for f in ${contents_TEMPLATES}
	${INSTALL_DATA} ${WRKSRC}/DTD/templates/${f} \
	    ${STAGEDIR}${EXAMPLESDIR}/templates/${f}
.endfor

.include <bsd.port.mk>
