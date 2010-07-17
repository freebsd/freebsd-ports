# New ports collection makefile for:	docbook-450
# Date created:		14 Jul 2008
# Whom:			Gabor Kovesdan <gabor@kovesdan.org>
#
# $FreeBSD$

PORTNAME=	docbook
PORTVERSION=	5.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.docbook.org/xml/5.0/

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	DocBook 5.0, designed for technical documentation

RUN_DEPENDS=	${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

USE_ZIP=	yes
NO_BUILD=	yes
LATEST_LINK=	${PORTNAME}-500

DOCBOOKDIR=	share/xml/${PORTNAME}/${PORTVERSION}
DOCSDIR=	${PREFIX}/${DOCBOOKDIR}/docs

PLIST_SUB+=	XMLCAT_ADD="${XMLCAT_ADD}" \
		XMLCAT_RM="${XMLCAT_RM}"

XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
XMLCAT=		${PREFIX}/share/xml/catalog.ports

XMLCAT_ADD=	${XMLCATMGR} -c ${XMLCAT} add nextCatalog \
		    ${PREFIX}/${DOCBOOKDIR}/catalog.xml
XMLCAT_RM=	${XMLCATMGR} -c ${XMLCAT} remove \
		    ${PREFIX}/${DOCBOOKDIR}/catalog.xml

OPTIONS=	DTD     	"XML DTD"   				on \
		SCHEMA		"W3C XML Schema"			on \
		RELAX_NG	"RELAX NG Schema"			on \
		SCHEMATRON	"Schematron constraints"		on \
		NVDL		"NVDL description"			on \
		TOOLS		"Tools for working with DocBook"	on \
		XMLCHARENT	"Install ISO 8879 XML entites"		on

.include <bsd.port.pre.mk>

.if defined(WITH_DTD)
PLIST_SUB+=	DTD=""
MODULES+=	dtd
.else
PLIST_SUB+=	DTD="@comment "
.endif
.if defined(WITH_SCHEMA)
PLIST_SUB+=	SCHEMA=""
MODULES+=	xsd
.else
PLIST_SUB+=	SCHEMA="@comment "
.endif
.if defined(WITH_RELAX_NG)
PLIST_SUB+=	RELAXNG=""
MODULES+=	rng
.else
PLIST_SUB+=	RELAXNG="@comment "
.endif
.if defined(WITH_SCHEMATRON)
PLIST_SUB+=	SCHEMATRON=""
MODULES+=	sch
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
MODULES+=	tools
.else
PLIST_SUB+=	TOOLS="@comment "
.endif
.if defined(WITH_XMLCHARENT)
RUN_DEPENDS+=	${LOCALBASE}/share/xml/xmlcharent/catalog:${PORTSDIR}/textproc/xmlcharent
.endif

do-install:
	${MKDIR} ${PREFIX}/${DOCBOOKDIR}
	${INSTALL_DATA} ${WRKSRC}/catalog.xml ${PREFIX}/${DOCBOOKDIR}
.for m in ${MODULES}
		${MKDIR} ${PREFIX}/${DOCBOOKDIR}/${m}
		files=$$(${FIND} ${WRKSRC}/${m} -type f); \
		for i in $${files}; do \
			${INSTALL_DATA} $${i} ${PREFIX}/${DOCBOOKDIR}/${m}; \
		done
.endfor
.if defined(WITH_NVDL)
	${MKDIR} ${PREFIX}/${DOCBOOKDIR}/nvdl
	${INSTALL_DATA} ${WRKSRC}/docbook.nvdl ${PREFIX}/${DOCBOOKDIR}/nvdl
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	files1=$$(${FIND} ${WRKSRC} -type f -depth 1| ${GREP} -v -e '.xml$$' -e '.nvdl$$'); \
	files2=$$(${FIND} ${WRKSRC}/docs -type f -depth 1); \
	for i in $${files1} $${files2}; do \
		${INSTALL_DATA} $${i} ${DOCSDIR}; \
	done
	${MKDIR} ${DOCSDIR}/images
	files=$$(${FIND} ${WRKSRC}/docs/images -type f); \
	for i in $${files}; do \
		${INSTALL_DATA} $${i} ${DOCSDIR}/images; \
	done
.endif

post-install:
	-${XMLCAT_ADD}

.include <bsd.port.post.mk>
