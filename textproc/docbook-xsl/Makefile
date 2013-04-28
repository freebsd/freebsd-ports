# $FreeBSD$

PORTNAME=	docbook-xsl
PORTVERSION=	1.76.1
CATEGORIES=	textproc
MASTER_SITES=	SF/docbook/${PORTNAME}/${PORTVERSION}:src \
		SF/docbook/${PORTNAME}-doc/${PORTVERSION}:doc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XSL DocBook stylesheets

BUILD_DEPENDS=	xmlcatmgr:${PORTSDIR}/textproc/xmlcatmgr
RUN_DEPENDS=	docbook>=0:${PORTSDIR}/textproc/docbook \
		xmlcatmgr:${PORTSDIR}/textproc/xmlcatmgr

USE_BZIP2=	yes
NO_BUILD=	yes

INSTDIR=	share/xsl/docbook
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST+=	INSTDIR="${INSTDIR}" \
		XMLCATMGR="${XMLCATMGR}" \
		CATALOG_PORTS="${LOCALBASE}/share/xml/catalog.ports"

XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr

MODULES=	common fo html images lib manpages params xhtml

OPTIONS_DEFINE=	ECLIPSE EPUB EXTENSIONS HIGHLIGHTING HTMLHELP JAVAHELP \
		PROFILING ROUNDTRIP SLIDES TEMPLATE TESTS TOOLS WEBSITE \
		XHTML11 DOCS
OPTIONS_DEFAULT=	ECLIPSE EPUB EXTENSIONS HIGHLIGHTING HTMLHELP JAVAHELP \
			PROFILING ROUNDTRIP SLIDES TEMPLATE TESTS TOOLS WEBSITE \
			XHTML11

ECLIPSE_DESC=		Eclipse modules
EPUB_DESC=		Epub modules
EXTENSIONS_DESC=	Extensions
HIGHLIGHTING_DESC=	highlighting modules
HTMLHELP_DESC=		HTML Help modules
JAVAHELP_DESC=		Java Help modules
PROFILING_DESC=		Profiling modules
ROUNDTRIP_DESC=		Roundtrip modules
SLIDES_DESC=		Slides modules
TEMPLATE_DESC=		Templates
TESTS_DESC=		Test tools
TOOLS_DESC=		Tools
WEBSITE_DESC=		Website modules
XHTML11_DESC=		XHTML 1.1 modules

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	${PORTNAME}-doc-${PORTVERSION}${EXTRACT_SUFX}:doc
.endif

.if ${PORT_OPTIONS:MECLIPSE}
PLIST_SUB+=	ECLIPSE=""
MODULES+=	eclipse
.else
PLIST_SUB+=	ECLIPSE="@comment "
.endif
.if ${PORT_OPTIONS:MEPUB}
PLIST_SUB+=	EPUB=""
MODULES+=	epub
.else
PLIST_SUB+=	EPUB="@comment "
.endif
.if ${PORT_OPTIONS:MEXTENSIONS}
PLIST_SUB+=	EXTENSIONS=""
MODULES+=	extensions
.else
PLIST_SUB+=	EXTENSIONS="@comment "
.endif
.if ${PORT_OPTIONS:MHIGHLIGHTING}
PLIST_SUB+=	HIGHLIGHTING=""
MODULES+=	highlighting
.else
PLIST_SUB+=	HIGHLIGHTING="@comment "
.endif
.if ${PORT_OPTIONS:MHTMLHELP}
PLIST_SUB+=	HTMLHELP=""
MODULES+=	htmlhelp
.else
PLIST_SUB+=	HTMLHELP="@comment "
.endif
.if ${PORT_OPTIONS:MJAVAHELP}
PLIST_SUB+=	JAVAHELP=""
MODULES+=	javahelp
.else
PLIST_SUB+=	JAVAHELP="@comment "
.endif
.if ${PORT_OPTIONS:MPROFILING}
PLIST_SUB+=	PROFILING=""
MODULES+=	profiling
.else
PLIST_SUB+=	PROFILING="@comment "
.endif
.if ${PORT_OPTIONS:MROUNDTRIP}
PLIST_SUB+=	ROUNDTRIP=""
MODULES+=	roundtrip
.else
PLIST_SUB+=	ROUNDTRIP="@comment "
.endif
.if ${PORT_OPTIONS:MSLIDES}
PLIST_SUB+=	SLIDES=""
MODULES+=	slides
.else
PLIST_SUB+=	SLIDES="@comment "
.endif
.if ${PORT_OPTIONS:MTEMPLATE}
PLIST_SUB+=	TEMPLATE=""
MODULES+=	template
.else
PLIST_SUB+=	TEMPLATE="@comment "
.endif
.if ${PORT_OPTIONS:MTESTS}
PLIST_SUB+=	TESTS=""
MODULES+=	tests
.else
PLIST_SUB+=	TESTS="@comment "
.endif
.if ${PORT_OPTIONS:MTOOLS}
PLIST_SUB+=	TOOLS=""
MODULES+=	tools
.else
PLIST_SUB+=	TOOLS="@comment "
.endif
.if ${PORT_OPTIONS:MWEBSITE}
PLIST_SUB+=	WEBSITE=""
MODULES+=	website
.else
PLIST_SUB+=	WEBSITE="@comment "
.endif
.if ${PORT_OPTIONS:MXHTML11}
PLIST_SUB+=	XHTML11=""
MODULES+=	xhtml-1_1
.else
PLIST_SUB+=	XHTML11="@comment "
.endif

post-extract:
	${FIND} ${WRKSRC} \( -name '.*' -or -name '*.sh' -or -name '*.LOG' \) -delete
	${FIND} ${WRKSRC}/extensions -type d -mindepth 1 -maxdepth 1 -print0 |\
		${XARGS} -0 ${RM} -rf

do-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc && ${TAR} -cf - . |\
		${TAR} -xf - -C${DOCSDIR})
.endif
.for m in ${MODULES}
		${MKDIR} ${PREFIX}/${INSTDIR}/${m}
		dirs=$$(${FIND} ${WRKSRC}/${m} -type d | ${SED} 's|^${WRKSRC}/${m}||g'); \
		for d in $${dirs}; do \
			files=$$(${FIND} ${WRKSRC}/${m}/$${d} -type f); \
			${MKDIR} ${PREFIX}/${INSTDIR}/${m}/$${d}; \
			for i in $${files}; do \
				${INSTALL_DATA} $${i} ${PREFIX}/${INSTDIR}/${m}/$${d}; \
			done; \
		done; \
		files=$$(${FIND} ${WRKSRC}/${m} -type f -depth 1); \
		for i in $${files}; do \
			${INSTALL_DATA} $${i} ${PREFIX}/${INSTDIR}/${m}; \
		done
.endfor
		files=$$(${FIND} ${WRKSRC} -type f -depth 1); \
		for i in $${files}; do \
			${INSTALL_DATA} $${i} ${PREFIX}/${INSTDIR}; \
		done

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
