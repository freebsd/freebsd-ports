PORTNAME=	freebsd-doc
PORTVERSION=	20230611
PORTEPOCH=	1
CATEGORIES=	misc docs
MASTER_SITES=	LOCAL/doceng
PKGNAMEPREFIX?=	en-

MAINTAINER=	doceng@FreeBSD.org
COMMENT?=	Documentation from the FreeBSD Documentation Project

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	docproj>=4.1:textproc/docproj

WRKSRC=		${WRKDIR}/doc/documentation
PLIST_SUB=	DOCBASE=${DOCBASE}
NO_ARCH=	yes

DOCLANG?=		en
DOCBASE?=		share/doc/freebsd

OPTIONS_DEFINE=	HTML PDF
OPTIONS_DEFAULT=	HTML PDF
OPTIONS_SUB=	yes
HTML_DESC=		HTML format
PDF_DESC=		PDF format

# HTML build needs to include English for all languages
.if ${DOCLANG:Men}
HTML_DOC_LANG= en
.else
HTML_DOC_LANG= ${DOCLANG} en
.endif

.include <bsd.port.options.mk>
.if empty(PORT_OPTIONS)
IGNORE=		at least one option must be enabled
.endif

.if ${PORT_OPTIONS:MPDF}
BUILD_DEPENDS+=	asciidoctor-pdf:textproc/rubygem-asciidoctor-pdf
.if ${DOCLANG:Mzh-cn} || ${DOCLANG:Mzh-tw}
BUILD_DEPENDS+=	docproj-fonts-cjk>0:textproc/docproj-fonts-cjk
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|enableGitInfo = true|#enableGitInfo = true|' \
		${WRKSRC}/config/_default/config.toml

do-build-HTML-on:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} DOC_LANG="${HTML_DOC_LANG}" \
		${MAKE} html
.if ${DOCLANG} == "en"
	@${RM} ${WRKSRC}/public/articles/index.html \
		${WRKSRC}/public/books/index.html
	@${RM} -r ${WRKSRC}/public/languages/
.else
	@${RM} -r ${WRKSRC}/public/${DOCLANG}/languages/
.endif

do-build-PDF-on:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} DOC_LANG="${DOCLANG}" \
		${MAKE} pdf

do-build:
	@${DO_NADA}

pre-install:
	${MKDIR} ${STAGEDIR}${DESTDIR}${PREFIX}/${DOCBASE}/${DOCLANG}

do-install-HTML-on:
.if ${DOCLANG} == "en"
	@${FIND} ${WRKSRC}/public/ -type f -name "*.html" | \
		${XARGS} ${REINPLACE_CMD} -i '' \
			-e 's|img src=../../../images|img src=../../images|g'
	@${FIND} ${WRKSRC}/public/ -name "*.orig" -delete
	${ECHO} "English HTML documents are in ../articles and ../books" \
		> ${STAGEDIR}${DESTDIR}${PREFIX}/${DOCBASE}/${DOCLANG}/README.txt
	${CP} -R ${WRKSRC}/public/* ${STAGEDIR}${DESTDIR}${PREFIX}/${DOCBASE}
.else
	${CP} -R ${WRKSRC}/public/${DOCLANG}/* ${STAGEDIR}${DESTDIR}${PREFIX}/${DOCBASE}/${DOCLANG}
.endif

do-install-PDF-on:
	cd ${WRKSRC}/public/ && ${FIND} ${DOCLANG}/ -type d -exec ${MKDIR} \
		${STAGEDIR}${DESTDIR}${PREFIX}/${DOCBASE}/{} \;
	cd ${WRKSRC}/public/ && ${FIND} ${DOCLANG}/ -type f -name "*.pdf" \
		-exec ${INSTALL_DATA} {} ${STAGEDIR}${DESTDIR}${PREFIX}/${DOCBASE}/{} \;

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
