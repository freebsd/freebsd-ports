PORTNAME=	docproj
PORTVERSION=	4.1.8
CATEGORIES=	textproc

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Meta-port for the FreeBSD Documentation Project
WWW=		https://www.freebsd.org/docproj

RUN_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor \
		gnuplot-lite>0:math/gnuplot-lite \
		gohugo>=0.115.4,1:www/gohugo \
		rougify:textproc/rubygem-rouge \
		rubygem-asciidoctor-diagram>0:textproc/rubygem-asciidoctor-diagram

USES=		metaport

OPTIONS_DEFINE=	EPUB FONTS-CJK GIT IGOR PDF TRANSLATOR VALE
OPTIONS_DEFAULT=	GIT IGOR PDF TRANSLATOR VALE

EPUB_DESC=	EPUB document support
FONTS-CJK_DESC=	Required CJK fonts to build PDF files
IGOR_DESC=		Igor automated proofreader for documentation
TRANSLATOR_DESC=	Tools for translators
VALE_DESC=	VALE Linting support

EPUB_RUN_DEPENDS=	asciidoctor-epub3:textproc/rubygem-asciidoctor-epub3
FONTS-CJK_RUN_DEPENDS=	docproj-fonts-cjk>0:textproc/docproj-fonts-cjk
GIT_RUN_DEPENDS=	git:devel/git
IGOR_RUN_DEPENDS=	igor:textproc/igor
PDF_RUN_DEPENDS=	asciidoctor-pdf:textproc/rubygem-asciidoctor-pdf
TRANSLATOR_RUN_DEPENDS=	po4a>=0.67:textproc/po4a
VALE_RUN_DEPENDS=	vale>0:textproc/vale

.include <bsd.port.mk>
