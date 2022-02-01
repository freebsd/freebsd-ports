PORTNAME=	docproj
PORTVERSION=	4.1.1
CATEGORIES=	textproc

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Meta-port for the FreeBSD Documentation Project

RUN_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor \
		hugo:www/gohugo \
		rougify:textproc/rubygem-rouge \

USES=		metaport

OPTIONS_DEFINE=	EPUB GIT IGOR PDF TRANSLATOR
OPTIONS_DEFAULT=	GIT IGOR PDF TRANSLATOR

EPUB_DESC=	EPUB document support
IGOR_DESC=		Igor automated proofreader for documentation
TRANSLATOR_DESC=	Tools for translators

EPUB_RUN_DEPENDS=	asciidoctor-epub3:textproc/rubygem-asciidoctor-epub3
GIT_RUN_DEPENDS=	git:devel/git
IGOR_RUN_DEPENDS=	igor:textproc/igor
PDF_RUN_DEPENDS=	asciidoctor-pdf:textproc/rubygem-asciidoctor-pdf
TRANSLATOR_RUN_DEPENDS=	po4a>=0.66_1:textproc/po4a

.include <bsd.port.mk>
