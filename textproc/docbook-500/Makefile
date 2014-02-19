# Created by: Gabor Kovesdan <gabor@kovesdan.org>
# $FreeBSD$

PORTVERSION=	5.0
PORTREVISION=	4
PKGNAMESUFFIX=	500

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	DocBook 5.0, designed for technical documentation

NO_ISOCAT=	yes
HAS_MANUAL_CATALOG_FILE=	yes
NO_DISTNAME_FIX=	yes
XML_DTD=	yes
MANUAL_DOCS=	yes
NO_DTD_SUBDIR=	yes

OPTIONS_DEFINE=	DTD SCHEMA RELAX_NG SCHEMATRON NVDL TOOLS XMLCHARENT DOCS
OPTIONS_DEFAULT=	DTD SCHEMA RELAX_NG SCHEMATRON NVDL TOOLS XMLCHARENT
DTD_DESC=		XML DTD
SCHEMA_DESC=		W3C XML Schema
RELAX_NG_DESC=		RELAX NG Schema
SCHEMATRON_DESC=	Schematron constraints
NVDL_DESC=		NVDL description
TOOLS_DESC=		Tools for working with DocBook
XMLCHARENT_DESC=	Install ISO 8879 XML entites
OPTIONS_SUB=	yes

XMLCHARENT_RUN_DEPENDS=	${LOCALBASE}/share/xml/xmlcharent/catalog:${PORTSDIR}/textproc/xmlcharent

PORTDOCS=	*

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${DTDDIR}/nvdl
	${MV} ${STAGEDIR}${PREFIX}/${DTDDIR}/docbook.nvdl ${STAGEDIR}${PREFIX}/${DTDDIR}/nvdl
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${STAGEDIR}${PREFIX}/${DTDDIR} && ${MV} ChangeLog README VERSION ${STAGEDIR}${DOCSDIR}
	cd ${STAGEDIR}${PREFIX}/${DTDDIR} && ${MV} docs/* ${STAGEDIR}${DOCSDIR} && ${RMDIR} docs

.include "../../textproc/docbook/bsd.docbook.mk"
.include <bsd.port.mk>
