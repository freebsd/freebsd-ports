# $FreeBSD$

PORTNAME=			nanomsg
PORTVERSION=			1.1.5
PORTREVISION=			1
CATEGORIES=			net

MAINTAINER=			crest@bultmann.eu
COMMENT=			Socket library that provides several common communication patterns

LICENSE=			MIT
LICENSE_FILE=			${WRKSRC}/COPYING

USES=				cmake pathfix
USE_LDCONFIG=			yes
USE_GITHUB=			yes
GH_ACCOUNT=			nanomsg

OPTIONS_DEFINE=			DOCS
OPTIONS_SUB=			yes

DOCS_DESC=			Build and/or install HTML and manpages

DOCS_BUILD_DEPENDS=		asciidoctor:textproc/rubygem-asciidoctor
DOCS_CMAKE_BOOL=		NN_ENABLE_DOC

PORTDOCS=			*

.include <bsd.port.mk>
