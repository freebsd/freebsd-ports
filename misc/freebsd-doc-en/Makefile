PORTNAME=	freebsd-doc
PORTVERSION=	20220702
PORTEPOCH=	1
CATEGORIES=	misc docs
MASTER_SITES=	LOCAL/blackend
PKGNAMEPREFIX?=	en-

MAINTAINER=	doceng@FreeBSD.org
COMMENT?=	Documentation from the FreeBSD Documentation Project

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	docproj>=4.0:textproc/docproj

WRKSRC=		${WRKDIR}/doc/documentation
PLIST_SUB=	DOCSDIR=${DOCBASE} \
		DOCLANG=${DOCLANG} \
		DOCLANG_PREFIX=${DOCLANG_PREFIX}
MAKE_ARGS=	${DOCFORMAT} \
		DOC_LANG="${DOCLANG}"
NO_ARCH=	yes

# To populate correctly the stage directory
TMPDESTDIR=	${STAGEDIR}${DESTDIR}/${PREFIX}/${DOCBASE}
DESTDIRNAME=	TMPDESTDIR

PLIST=		${WRKDIR}/pkg-plist

DOCLANG?=		en
DOCLANG_PREFIX?=	${DOCLANG:C/_.*$//}
DOCBASE?=		share/doc/freebsd

# HTML format disabled until separate localized-only build will work again
#AVAILABLEFORMATS=	HTML PDF
AVAILABLEFORMATS=	PDF

OPTIONS_DEFINE=		${AVAILABLEFORMATS}
OPTIONS_DEFAULT=	PDF
HTML_DESC=		Single HTML file per document
PDF_DESC=		PDF format

# if PACKAGE_BUILDING=yes, enable all of $AVAILABLEFORMATS.
.if defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT+=	${AVAILABLEFORMATS}
.endif

.include <bsd.port.options.mk>

.for O in ${AVAILABLEFORMATS}
.if ${PORT_OPTIONS:M${O}}
DOCFORMAT+=	${O:tl}
PLIST_FORMATS+=	${O:tl}
.endif
.endfor

.if ${PORT_OPTIONS:MPDF}
BUILD_DEPENDS+=	asciidoctor-pdf:textproc/rubygem-asciidoctor-pdf
.endif

# when html is defined as the format, add HTML_COMMON.
.if ${PORT_OPTIONS:MHTML}
PLIST_FORMATS+=	html-common
.endif

# example files, scripts, etc. coming with the doc and common
# directories for all formats.
PLIST_FORMATS+=	extras common

pre-build:
.for i in ${PLIST_FORMATS:S,^,${.CURDIR}/pkg-plist.,}
	if ${TEST} -f ${i}; then \
		${CAT} ${i} >> ${PLIST}; \
	fi
.endfor

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS}

do-install:
	${MKDIR} ${STAGEDIR}${DESTDIR}${PREFIX}/${DOCBASE}
	${CP} -R ${WRKSRC}/public/* ${STAGEDIR}${DESTDIR}${PREFIX}/${DOCBASE}
	if ${TEST} -f ${.CURDIR}/pkg-plist.extras; then \
		${CAT} ${.CURDIR}/pkg-plist.extras | \
		${SED} -e 's|%%DOCSDIR%%/%%DOCLANG%%||' | \
		${XARGS} -t -I % ${CP} -v ${WRKSRC}/static/source/% ${STAGEDIR}${DESTDIR}${PREFIX}/${DOCBASE}/${DOCLANG}%; \
	fi

.include <bsd.port.mk>
