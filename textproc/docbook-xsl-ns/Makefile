# $FreeBSD$

PORTNAME=	docbook-xsl-ns
PORTVERSION=	1.78.1
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	SF/docbook/${PORTNAME}/${PORTVERSION}:src \
		SF/docbook/docbook-xsl-doc/${PORTVERSION}:doc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Namespace-aware DocBook XSLT stylesheets

BUILD_DEPENDS=	xmlcatmgr:${PORTSDIR}/textproc/xmlcatmgr
RUN_DEPENDS=	docbook>=0:${PORTSDIR}/textproc/docbook \
		xmlcatmgr:${PORTSDIR}/textproc/xmlcatmgr

USE_BZIP2=	yes
NO_BUILD=	yes

INSTDIR=	share/xsl/docbook-ns
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
DOCSRC=		${WRKDIR}/docbook-xsl-${PORTVERSION}

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST+=	INSTDIR="${INSTDIR}" \
		XMLCATMGR="${XMLCATMGR}" \
		CATALOG_PORTS="${LOCALBASE}/share/xml/catalog.ports"

XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
CATALOG_XSL=	${WRKSRC}/catalog

DXVERSIONS=	1.36 1.37 1.38 1.39 1.40 1.41 1.42 1.43 1.44 1.45 1.46 1.47 \
		1.48 1.49 1.50.0 1.51.0 1.51.1 1.52.0 1.52.1 1.52.2 1.53.0 \
		1.54.0 1.54.1 1.55.0 1.56.0 1.56.1 1.57.0 1.58.0 1.58.1 \
		1.59.0 1.59.1 1.59.2 1.60.0 1.60.1 1.61.0 1.61.1 1.61.2 \
		1.61.3 1.62.0 1.62.1 1.62.2 1.62.3 1.62.4 1.63.0 1.64.0 \
		1.64.1 1.65.0 1.65.1 1.66.0 1.66.1 1.67.0 1.67.2 1.68.0 \
		1.68.1 1.69.0 1.69.1 1.70.0 1.70.1 1.71.0 1.71.1 1.78.1 \
		current

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	docbook-xsl-doc-${PORTVERSION}${EXTRACT_SUFX}:doc
.endif

post-extract:
	${FIND} ${WRKSRC} \( -name '.*' -or -name '*.sh' -or -name '*.LOG' \) -delete
	${FIND} ${WRKSRC}/extensions -type d -mindepth 1 -maxdepth 1 -print0 |\
		${XARGS} -0 ${RM} -rf

do-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${DOCSRC}/doc && \
	${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \; &&  \
	${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
.endif
	${XMLCATMGR} -c ${CATALOG_XSL} create
.for dxversion in ${DXVERSIONS}
	${XMLCATMGR} -c "${CATALOG_XSL}" add rewriteSystem \
		http://docbook.sourceforge.net/release/xsl/${dxversion} \
		"file://${PREFIX}/${INSTDIR}"
	${XMLCATMGR} -c "${CATALOG_XSL}" add rewriteURI \
		http://docbook.sourceforge.net/release/xsl/${dxversion} \
		"file://${PREFIX}/${INSTDIR}"
.endfor
	${MKDIR} ${PREFIX}/${INSTDIR}
	cd ${WRKSRC} && \
	${FIND} . -type d -exec ${MKDIR} ${PREFIX}/${INSTDIR}/{} \; &&  \
	${FIND} . -type f -exec ${INSTALL_DATA} {} ${PREFIX}/${INSTDIR}/{} \;

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

plist:
	@cd ${WRKSRC} && \
	${FIND} . -type f -exec echo ${INSTDIR}/{} \; | ${SED} 's|/./|/|g'
	@${ECHO_CMD} ${INSTDIR}/catalog
	@cd ${WRKSRC} && \
	${FIND} . -type d -exec echo @dirrm ${INSTDIR}/{} \; | ${SED} 's|/./|/|g' | ${SORT} -r
	@${ECHO_CMD} @dirrmtry ${INSTDIR}
	@${ECHO_CMD} @dirrmtry share/xsl
	@cd ${DOCSRC}/doc && \
	${FIND} . -type f -exec echo %%PORTDOCS%%%%DOCSDIR%%/{} \; | ${SED} 's|/./|/|g'
	@cd ${DOCSRC}/doc && \
	${FIND} . -type d -exec echo %%PORTDOCS%%@dirrm %%DOCSDIR%%/{} \; | ${SED} 's|/./|/|g' | ${SORT} -r
	@${ECHO_CMD} @dirrmtry ${DOCSDIR}

.include <bsd.port.mk>
