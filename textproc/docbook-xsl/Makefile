# $FreeBSD$

PORTNAME=	docbook-xsl
PORTVERSION=	1.76.1
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	SF/docbook/${PORTNAME}/${PORTVERSION}:src \
		SF/docbook/${PORTNAME}-doc/${PORTVERSION}:doc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	XSL DocBook stylesheets

BUILD_DEPENDS=	xmlcatmgr:textproc/xmlcatmgr
RUN_DEPENDS=	docbook>=0:textproc/docbook \
		xmlcatmgr:textproc/xmlcatmgr

USES=	tar:bzip2
NO_BUILD=	yes

INSTDIR=	share/xsl/docbook
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

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

DXVERSIONS=	1.36 1.37 1.38 1.39 1.40 1.41 1.42 1.43 1.44 1.45 1.46 1.47 \
		1.48 1.49 1.50.0 1.51.0 1.51.1 1.52.0 1.52.1 1.52.2 1.53.0 \
		1.54.0 1.54.1 1.55.0 1.56.0 1.56.1 1.57.0 1.58.0 1.58.1 \
		1.59.0 1.59.1 1.59.2 1.60.0 1.60.1 1.61.0 1.61.1 1.61.2 \
		1.61.3 1.62.0 1.62.1 1.62.2 1.62.3 1.62.4 1.63.0 1.64.0 \
		1.64.1 1.65.0 1.65.1 1.66.0 1.66.1 1.67.0 1.67.2 1.68.0 \
		1.68.1 1.69.0 1.69.1 1.70.0 1.70.1 1.71.0 1.71.1 current

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
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${TAR} -cf - . |\
		${TAR} -xf - -C${STAGEDIR}${DOCSDIR})
.endif
.for m in ${MODULES}
		${MKDIR} ${STAGEDIR}${PREFIX}/${INSTDIR}/${m}
		dirs=$$(${FIND} ${WRKSRC}/${m} -type d | ${SED} 's|^${WRKSRC}/${m}||g'); \
		for d in $${dirs}; do \
			files=$$(${FIND} ${WRKSRC}/${m}/$${d} -type f); \
			${MKDIR} ${STAGEDIR}${PREFIX}/${INSTDIR}/${m}/$${d}; \
			for i in $${files}; do \
				${INSTALL_DATA} $${i} ${STAGEDIR}${PREFIX}/${INSTDIR}/${m}/$${d}; \
			done; \
		done; \
		files=$$(${FIND} ${WRKSRC}/${m} -type f -depth 1); \
		for i in $${files}; do \
			${INSTALL_DATA} $${i} ${STAGEDIR}${PREFIX}/${INSTDIR}/${m}; \
		done
.endfor
		files=$$(${FIND} ${WRKSRC} -type f -depth 1); \
		for i in $${files}; do \
			${INSTALL_DATA} $${i} ${STAGEDIR}${PREFIX}/${INSTDIR}; \
		done

.include <bsd.port.mk>
