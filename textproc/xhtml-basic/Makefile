# Created by: nectar
# $FreeBSD$

PORTNAME=	xhtml-basic
PORTVERSION=	1.0.${RECDATE}
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.w3.org/TR/2000/REC-${PORTNAME}-${RECDATE}/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	W3C's XHTML Basic DTD

OPTIONS_DEFINE=	DOCS

RUN_DEPENDS=	xmlcatmgr:textproc/xmlcatmgr \
		${LOCALBASE}/share/xml/dtd/xhtml-modularization/catalog.xml:textproc/xhtml-modularization

RECDATE=	20001219

NO_MTREE=	YES
NO_BUILD=	YES
WRKSRC=		${WRKDIR}/REC-${PORTNAME}-${RECDATE}

PORTDATA=	xhtml-basic10-model-1.mod \
		xhtml-basic10.cat \
		xhtml-basic10.dtd \
		xml1.dcl

PLIST_FILES+=	%%DATADIR%%/catalog.xml

PORTDOCS=	Overview.html \
		W3C-REC.css \
		logo-REC.png \
		w3c_home.png \
		xhtml-basic.css

SUB_FILES=	catalog.xml
DATADIR=	${PREFIX}/share/xml/dtd/xhtml-basic

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDATA} \
		${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${WRKDIR}/catalog.xml \
		${STAGEDIR}${DATADIR}/catalog.xml

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} \
		${STAGEDIR}${DOCSDIR})


.include <bsd.port.mk>
