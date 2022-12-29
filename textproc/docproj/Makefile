PORTNAME=	docproj
PORTVERSION=	4.1.5
CATEGORIES=	textproc

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Meta-port for the FreeBSD Documentation Project
WWW=		https://www.freebsd.org/docproj

RUN_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor \
		hugo:www/gohugo \
		rougify:textproc/rubygem-rouge \

USES=		metaport

OPTIONS_DEFINE=	EPUB GIT IGOR PDF TRANSLATOR VALE
OPTIONS_DEFAULT=	GIT IGOR PDF TRANSLATOR VALE

EPUB_DESC=	EPUB document support
IGOR_DESC=		Igor automated proofreader for documentation
TRANSLATOR_DESC=	Tools for translators
VALE_DESC=	VALE Linting support

EPUB_RUN_DEPENDS=	asciidoctor-epub3:textproc/rubygem-asciidoctor-epub3
GIT_RUN_DEPENDS=	git:devel/git
IGOR_RUN_DEPENDS=	igor:textproc/igor
PDF_RUN_DEPENDS=	asciidoctor-pdf:textproc/rubygem-asciidoctor-pdf
TRANSLATOR_RUN_DEPENDS=	po4a>=0.67:textproc/po4a
VALE_RUN_DEPENDS=	vale>0:textproc/vale

.include <bsd.port.mk>
