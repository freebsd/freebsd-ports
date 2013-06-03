# $FreeBSD$

PORTNAME=	docbook-xsl-ns
PORTVERSION=	1.78.1
PORTREVISION=	1
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

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=    docbook-xsl-doc-${PORTVERSION}${EXTRACT_SUFX}:doc
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
	@cd ${DOCSRC}/doc && \
	${FIND} . -type f -exec echo %%PORTDOCS%%%%DOCSDIR%%/{} \; | ${SED} 's|/./|/|g'
	@cd ${DOCSRC}/doc && \
	${FIND} . -type d -exec echo %%PORTDOCS%%@dirrm %%DOCSDIR%%/{} \; | ${SED} 's|/./|/|g' | ${SORT} -r
	@${ECHO_CMD} @dirrmtry ${DOCSDIR}

.include <bsd.port.mk>
