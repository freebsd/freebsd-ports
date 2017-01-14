# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Sablot
PORTVERSION=	1.0.3
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	SF/sablotron/sablotron-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML toolkit implementing XSLT 1.0, XPath 1.0 and DOM Level2

LICENSE=	MPL GPLv2+
LICENSE_COMB=	dual

LIB_DEPENDS=	libexpat.so:textproc/expat2

GNU_CONFIGURE=	yes
USES=		gmake iconv libtool localbase:ldflags
USE_LDCONFIG=	yes
LDFLAGS+=	${ICONV_LIB}

PORTDOCS=	*

OPTIONS_DEFINE=	DEBUGGER DISABLE_META DOCS DOCUMENT_ERRORS DOM

DEBUGGER_DESC=		Enable debugger
DISABLE_META_DESC=	Do not output the META html tag
DOCUMENT_ERRORS_DESC=	Allow document errors
DOM_DESC=		Use DOM

OPTIONS_DEFAULT=	DOM DOCUMENT_ERRORS

DEBUGGER_CONFIGURE_ENABLE=	debugger
DISABLE_META_CONFIGURE_ON=	--disable-adding-meta
DOCS_BUILD_DEPENDS=		p5-XML-Parser>=0:textproc/p5-XML-Parser
DOCS_CONFIGURE_ON=		--with-html-dir=${DOCSDIR}
DOCS_USES=			perl5
DOCS_USE=			PERL5=build
DOM_CONFIGURE_ENABLE=		dom
DOCUMENT_ERRORS_CONFIGURE_ENABLE=	document-errors

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/apidoc//' ${WRKSRC}/doc/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsablot.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README README_JS RELEASE \
		doc/misc/DEBUGGER doc/misc/NOTES ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
