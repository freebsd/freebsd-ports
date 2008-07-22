# New ports collection makefile for:	docbook-450
# Date created:		14 Jul 2008
# Whom:			Gabor Kovesdan <gabor@kovesdan.org>
#
# $FreeBSD$

PORTNAME=	docbook
PORTVERSION=	5.0
CATEGORIES=	textproc
MASTER_SITES=	http://www.docbook.org/xml/5.0/

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	DocBook 5.0, designed for technical documentation

RUN_DEPENDS=	${LOCALBASE}/${ISOCAT}:${PORTSDIR}/textproc/iso8879 \
		${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

USE_ZIP=	yes
NO_BUILD=	yes
LATEST_LINK=	${PORTNAME}-500

DOCBOOKDIR=	share/xml/${PORTNAME}/${PORTVERSION}
DOCSDIR=	${PREFIX}/${DOCBOOKDIR}/docs

XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS_XML=	${PREFIX}/share/xml/catalog.ports
REGIST_CAT_FLAGS_XML=	-c ${CATALOG_PORTS_XML} \
			add nextCatalog ${DOCBOOKDIR}/catalog.xml
UNREGIST_CAT_FLAGS_XML=	-c ${CATALOG_PORTS_XML} \
			remove nextCatalog ${DOCBOOKDIR}/catalog.xml

OPTIONS=	DTD     	"XML DTD"   				on \
		SCHEMA		"W3C XML Schema"			on \
		RELAX_NG	"RELAX NG Schema"			on \
		SCHEMATRON	"Schematron constraints"		on \
		NVDL		"NVDL description"			on \
		TOOLS		"Tools for working with DocBook"	on

.include <bsd.port.pre.mk>

.if defined(WITH_DTD)
PLIST_SUB+=	DTD=""
.else
PLIST_SUB+=	DTD="@comment "
.endif
.if defined(WITH_SCHEMA)
PLIST_SUB+=	SCHEMA=""
.else
PLIST_SUB+=	SCHEMA="@comment "
.endif
.if defined(WITH_RELAX_NG)
PLIST_SUB+=	RELAXNG=""
.else
PLIST_SUB+=	RELAXNG="@comment "
.endif
.if defined(WITH_SCHEMATRON)
PLIST_SUB+=	SCHEMATRON=""
.else
PLIST_SUB+=	SCHEMATRON="@comment "
.endif
.if defined(WITH_NVDL)
PLIST_SUB+=	NVDL=""
.else
PLIST_SUB+=	NVDL="@comment "
.endif
.if defined(WITH_TOOLS)
PLIST_SUB+=	TOOLS=""
.else
PLIST_SUB+=	TOOLS="@comment "
.endif
.if defined(NOPORTDOCS)
PLIST_SUB+=	NOPORTDOCS="@comment "
.else
PLIST_SUB+=	NOPORTDOCS=""
.endif

do-install:
	${MKDIR} ${PREFIX}/${DOCBOOKDIR}
	${INSTALL_DATA} ${WRKSRC}/catalog.xml ${PREFIX}/${DOCBOOKDIR}
.if defined(WITH_DTD)
	${MKDIR} ${PREFIX}/${DOCBOOKDIR}/dtd
	${INSTALL_DATA} ${WRKSRC}/dtd/docbook.dtd ${PREFIX}/${DOCBOOKDIR}/dtd
.endif
.if defined(WITH_SCHEMA)
	${MKDIR} ${PREFIX}/${DOCBOOKDIR}/xsd
.for i in docbook.xsd xlink.xsd xml.xsd
	${INSTALL_DATA} ${WRKSRC}/xsd/${i} ${PREFIX}/${DOCBOOKDIR}/xsd
.endfor
.endif
.if defined(WITH_RELAX_NG)
	${MKDIR} ${PREFIX}/${DOCBOOKDIR}/rng
.for i in docbook.rnc docbook.rng docbookxi.rnc docbookxi.rng
	${INSTALL_DATA} ${WRKSRC}/rng/${i} ${PREFIX}/${DOCBOOKDIR}/rng
.endfor
.endif
.if defined(WITH_SCHEMATRON)
	${MKDIR} ${PREFIX}/${DOCBOOKDIR}/sch
	${INSTALL_DATA} ${WRKSRC}/sch/docbook.sch ${PREFIX}/${DOCBOOKDIR}/sch
.endif
.if defined(WITH_NVDL)
	${MKDIR} ${PREFIX}/${DOCBOOKDIR}/nvdl
	${INSTALL_DATA} ${WRKSRC}/docbook.nvdl ${PREFIX}/${DOCBOOKDIR}/nvdl
.endif
.if defined(WITH_TOOLS)
	${MKDIR} ${PREFIX}/${DOCBOOKDIR}/tools
.for i in db4-entities.pl db4-upgrade.xsl
	${INSTALL_DATA} ${WRKSRC}/tools/${i} ${PREFIX}/${DOCBOOKDIR}/tools
.endfor
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ChangeLog README VERSION docs/docbook-5.0-spec-cd-01.html \
	docs/docbook-5.0-spec-cd-01.pdf docs/docbook-5.0-spec-cd-01.xml \
	docs/howto.html docs/howto.pdf docs/howto.xml
		${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	${MKDIR} ${DOCSDIR}/images
.for i in emacs.png oxygen1.png oxygen2.png oxygen3.png xxe.png
	${INSTALL_DATA} ${WRKSRC}/docs/images/${i} ${DOCSDIR}/images
.endfor
.endif

post-install:
	-${XMLCATMGR} ${REGIST_CAT_FLAGS_XML}

.include <bsd.port.post.mk>
