# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Sablot
PORTVERSION=	1.0.3
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	SF/sablotron/sablotron-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML toolkit implementing XSLT 1.0, XPath 1.0 and DOM Level2

LICENSE=	GPLv2

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2

OPTIONS_DEFINE=	DEBUGGER DISABLE_META DOCS DOCUMENT_ERRORS DOM

DEBUGGER_DESC=		Enable debugger
DISABLE_META_DESC=	Do not output the META html tag
DOCUMENT_ERRORS_DESC=	Allow document errors
DOM_DESC=		Use DOM

OPTIONS_DEFAULT=	DOM DOCUMENT_ERRORS

DEBUGGER_CONFIGURE_ENABLE=	debugger
DISABLE_META_CONFIGURE_ON=	--disable-adding-meta
DOCS_BUILD_DEPENDS=		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
DOCS_CONFIGURE_ON=		--with-html-dir=${DOCSDIR}
DOCS_USES=			perl5
DOCS_USE=			PERL5=build
DOM_CONFIGURE_ENABLE=		dom
DOCUMENT_ERRORS_CONFIGURE_ENABLE=	document-errors

GNU_CONFIGURE=	yes
USES=		gmake iconv libtool
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
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/apidoc//' ${WRKSRC}/doc/Makefile.in
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

.include <bsd.port.mk>
