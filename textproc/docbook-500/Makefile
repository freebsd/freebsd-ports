# Created by: Gabor Kovesdan <gabor@kovesdan.org>
# $FreeBSD$

PORTNAME=	docbook
PORTVERSION=	5.0
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://www.docbook.org/xml/5.0/
PKGNAMESUFFIX=	500
EXTRACT_SUFX=	.zip

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	DocBook 5.0, designed for technical documentation

RUN_DEPENDS=	${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

NO_BUILD=	yes

DTDDIR=		share/xml/${PORTNAME}/${PORTVERSION}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}/${PORTVERSION}

PLIST_SUB+=	XMLCATMGR=${XMLCATMGR} XMLCAT=${XMLCAT} \
		DTDDIR=${DTDDIR}

XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
XMLCAT=		${PREFIX}/share/xml/catalog.ports

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

XMLCHARENT_RUN_DEPENDS+=	${LOCALBASE}/share/xml/xmlcharent/catalog:${PORTSDIR}/textproc/xmlcharent

PORTDOCS=	*

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${DTDDIR}
	${INSTALL_DATA} ${WRKSRC}/catalog.xml ${STAGEDIR}${PREFIX}/${DTDDIR}
.for m in dtd xsd rng sch tools
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${m} ${STAGEDIR}${PREFIX}/${DTDDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/${DTDDIR}/nvdl
	${INSTALL_DATA} ${WRKSRC}/docbook.nvdl ${STAGEDIR}${PREFIX}/${DTDDIR}/nvdl
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ChangeLog README VERSION ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
