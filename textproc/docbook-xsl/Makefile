# New ports collection makefile for:   docbook-xml
# Date created:        17 January 2002
# Whom:                des
#
# $FreeBSD$
#

PORTNAME=	docbook-xsl
PORTVERSION=	1.75.1
CATEGORIES=	textproc
MASTER_SITES=	SF/docbook/${PORTNAME}/${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	skv@FreeBSD.org
COMMENT=	XSL DocBook stylesheets

RUN_DEPENDS=	${LOCALBASE}/share/xml/docbook:${PORTSDIR}/textproc/docbook

.if !defined(NOPORTDOCS)
DISTFILES+=	${PORTNAME}-doc-${PORTVERSION}${EXTRACT_SUFX}
.endif

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

MODULES=	common images lib params

OPTIONS=	ECLIPSE		"Eclipse modules"		on \
		EPUB		"Epub modules"			on \
		EXTENSIONS	"Extensions"			on \
		FO		"XSL-FO modules"		on \
		HIGHLIGHTING	"highlighting modules"		on \
		HTML		"HTML modules"			on \
		HTMLHELP	"HTML Help modules"		on \
		JAVAHELP	"Java Help modules"		on \
		MANPAGES	"Manpage modules"		on \
		PROFILING	"Profiling modules"		on \
		ROUNDTRIP	"Roundtrip modules"		on \
		SLIDES		"Slides modules"		on \
		TEMPLATE	"Templates"			on \
		TESTS		"Test tools"			on \
		TOOLS		"Tools"				on \
		WEBSITE		"Website modules"		on \
		XHTML		"XHTML modules"			on \
		XHTML11		"XHTML 1.1 modules"		on

.include <bsd.port.pre.mk>

.if defined(WITH_ECLIPSE)
PLIST_SUB+=	ECLIPSE=""
MODULES+=	eclipse
.else
PLIST_SUB+=	ECLIPSE="@comment "
.endif
.if defined(WITH_EPUB)
PLIST_SUB+=	EPUB=""
MODULES+=	epub
.else
PLIST_SUB+=	EPUB="@comment "
.endif
.if defined(WITH_EXTENSIONS)
PLIST_SUB+=	EXTENSIONS=""
MODULES+=	extensions
.else
PLIST_SUB+=	EXTENSIONS="@comment "
.endif
.if defined(WITH_FO)
PLIST_SUB+=	FO=""
MODULES+=	fo
.else
PLIST_SUB+=	FO="@comment "
.endif
.if defined(WITH_HIGHLIGHTING)
PLIST_SUB+=	HIGHLIGHTING=""
MODULES+=	highlighting
.else
PLIST_SUB+=	HIGHLIGHTING="@comment "
.endif
.if defined(WITH_HTML)
PLIST_SUB+=	HTML=""
MODULES+=	html
.else
PLIST_SUB+=	HTML="@comment "
.endif
.if defined(WITH_HTMLHELP)
PLIST_SUB+=	HTMLHELP=""
MODULES+=	htmlhelp
.else
PLIST_SUB+=	HTMLHELP="@comment "
.endif
.if defined(WITH_JAVAHELP)
PLIST_SUB+=	JAVAHELP=""
MODULES+=	javahelp
.else
PLIST_SUB+=	JAVAHELP="@comment "
.endif
.if defined(WITH_MANPAGES)
PLIST_SUB+=	MANPAGES=""
MODULES+=	manpages
.else
PLIST_SUB+=	MANPAGES="@comment "
.endif
.if defined(WITH_PROFILING)
PLIST_SUB+=	PROFILING=""
MODULES+=	profiling
.else
PLIST_SUB+=	PROFILING="@comment "
.endif
.if defined(WITH_ROUNDTRIP)
PLIST_SUB+=	ROUNDTRIP=""
MODULES+=	roundtrip
.else
PLIST_SUB+=	ROUNDTRIP="@comment "
.endif
.if defined(WITH_SLIDES)
PLIST_SUB+=	SLIDES=""
MODULES+=	slides
.else
PLIST_SUB+=	SLIDES="@comment "
.endif
.if defined(WITH_TEMPLATE)
PLIST_SUB+=	TEMPLATE=""
MODULES+=	template
.else
PLIST_SUB+=	TEMPLATE="@comment "
.endif
.if defined(WITH_TESTS)
PLIST_SUB+=	TESTS=""
MODULES+=	tests
.else
PLIST_SUB+=	TESTS="@comment "
.endif
.if defined(WITH_TOOLS)
PLIST_SUB+=	TOOLS=""
MODULES+=	tools
.else
PLIST_SUB+=	TOOLS="@comment "
.endif
.if defined(WITH_WEBSITE)
PLIST_SUB+=	WEBSITE=""
MODULES+=	website
.else
PLIST_SUB+=	WEBSITE="@comment "
.endif
.if defined(WITH_XHTML)
PLIST_SUB+=	XHTML=""
MODULES+=	xhtml
.else
PLIST_SUB+=	XHTML="@comment "
.endif
.if defined(WITH_XHTML11)
PLIST_SUB+=	XHTML11=""
MODULES+=	xhtml-1_1
.else
PLIST_SUB+=	XHTML11="@comment "
.endif

post-extract:
	${FIND} ${WRKSRC} -name '.#*' -or -name '.gitignore' -delete
	${FIND} ${WRKSRC}/extensions -type d -mindepth 1 -maxdepth 1 -print0 |\
		${XARGS} -0 ${RM} -rf

do-install:
.if !defined(NOPORTDOCS)
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

.include <bsd.port.post.mk>
