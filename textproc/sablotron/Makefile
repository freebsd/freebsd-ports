# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Sablot
PORTVERSION=	1.0.3
CATEGORIES=	textproc
MASTER_SITES=	SF/sablotron/sablotron-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML toolkit implementing XSLT 1.0, XPath 1.0 and DOM Level2

LICENSE=	GPLv2

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2

OPTIONS_DEFINE=	CHECK_LEAKS DEBUGGER DISABLE_META DOCS \
		DOCUMENT_ERRORS DOM ICONV_TYPECAST

CHECK_LEAKS_DESC=	Enable memory leaks checking
DEBUGGER_DESC=		Enable debugger
DISABLE_META_DESC=	Do not output the META html tag
DOCUMENT_ERRORS_DESC=	Allow document errors
DOM_DESC=		Use DOM
ICONV_TYPECAST_DESC=	Use iconv typecast

OPTIONS_DEFAULT=	DOM DOCUMENT_ERRORS

CHECK_LEAKS_CONFIGURE_ENABLE=	check-leaks
DEBUGGER_CONFIGURE_ENABLE=	debugger
DISABLE_META_CONFIGURE_ON=	--disable-adding-meta
DOCS_BUILD_DEPENDS=		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
DOCS_CONFIGURE_ON=		--with-html-dir=${DOCSDIR}
DOM_CONFIGURE_ENABLE=		dom
DOCUMENT_ERRORS_CONFIGURE_ENABLE=	document-errors
ICONV_TYPECAST_CONFIGURE_ENABLE=	iconv-typecast

SHLIB_MAJOR=	70	# API changes counter
PLIST_SUB+=	SHLIB_MAJOR="${SHLIB_MAJOR}"

USES=		gmake iconv perl5
USE_PERL5=	build patch
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBTOOL=${LIBTOOL}
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lexpat ${ICONV_LIB}

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	README README_JS RELEASE

DOCSRCDIR2=	${WRKSRC}/doc/misc
DOCSDIR2=	${DOCSDIR}/doc/misc
DOC_FILES2=	DEBUGGER NOTES

.include <bsd.port.options.mk>

post-patch:
	@${PERL} -pi -e \
	's!(?<=libsablot_la_LDFLAGS = -version-info )(\d+):(\d+):\1!${SHLIB_MAJOR}:$$1:${SHLIB_MAJOR}!;' \
		${WRKSRC}/src/engine/Makefile.in
	@${PERL} -pi -e 's!se // !! if $$. = 407' ${WRKSRC}/src/engine/base.h
.if ! ${PORT_OPTIONS:MDOCS}
	@${PERL} -pi -e 's!(?<=SUBDIRS = )(.*)!man!' ${WRKSRC}/doc/Makefile.in
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

.include <bsd.port.mk>
