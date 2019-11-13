# $FreeBSD$

PORTNAME=	docbook-xsl
PORTVERSION=	1.79.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/docbook/docbook-xsl/${PORTVERSION}:src \
		SF/docbook/docbook-xsl-doc/${PORTVERSION}:doc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XSL DocBook stylesheets

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xmlcatmgr:textproc/xmlcatmgr
RUN_DEPENDS=	docbook>=0:textproc/docbook \
		xmlcatmgr:textproc/xmlcatmgr

USES=		tar:bzip2

NO_ARCH=	yes
NO_BUILD=	yes

INSTDIR=	share/xsl/docbook
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

MODULES=	common fo html images lib manpages params xhtml

OPTIONS_DEFINE=	ECLIPSE EPUB EXTENSIONS HIGHLIGHTING HTMLHELP JAVAHELP \
		PROFILING ROUNDTRIP SLIDES TEMPLATE TESTS TOOLS WEBSITE \
		XHTML11 DOCS
OPTIONS_DEFAULT=ECLIPSE EPUB EXTENSIONS HIGHLIGHTING HTMLHELP JAVAHELP \
		PROFILING ROUNDTRIP SLIDES TEMPLATE TESTS TOOLS WEBSITE \
		XHTML11
OPTIONS_SUB=	yes

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

DOCS_DISTFILES=		docbook-xsl-doc-${PORTVERSION}${EXTRACT_SUFX}:doc

ECLIPSE_VARS=		MODULES+=eclipse
EPUB_VARS=		MODULES+=epub
EXTENSIONS_VARS=	MODULES+=extensions
HIGHLIGHTING_VARS=	MODULES+=highlighting
HTMLHELP_VARS=		MODULES+=htmlhelp
JAVAHELP_VARS=		MODULES+=javahelp
PROFILING_VARS=		MODULES+=profiling
ROUNDTRIP_VARS=		MODULES+=roundtrip
SLIDES_VARS=		MODULES+=slides
TEMPLATE_VARS=		MODULES+=template
TESTS_VARS=		MODULES+=tests
TOOLS_VARS=		MODULES+=tools
WEBSITE_VARS=		MODULES+=website
XHTML11_VARS=		MODULES+=xhtml-1_1

.include <bsd.port.options.mk>

post-extract:
	${FIND} ${WRKSRC} \( -name '.*' -or -name '*.sh' -or -name '*.LOG' \) -delete
	${FIND} ${WRKSRC}/extensions -type d -mindepth 1 -maxdepth 1 -print0 |\
		${XARGS} -0 ${RM} -r

do-install:
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

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

# maintainer section:

.if defined(MAINTAINER_MODE)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src \
		docbook-xsl-doc-${PORTVERSION}${EXTRACT_SUFX}:doc
.endif

.include <bsd.port.mk>
