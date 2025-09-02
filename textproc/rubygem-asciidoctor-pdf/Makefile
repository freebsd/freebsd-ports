PORTNAME=	asciidoctor-pdf
PORTVERSION=	2.3.19
PORTREVISION=	3
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Convert AsciiDoc documents to PDF
WWW=		https://docs.asciidoctor.org/pdf-converter/latest/ \
		https://github.com/asciidoctor/asciidoctor-pdf

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-asciidoctor>=2.0<3:textproc/rubygem-asciidoctor \
		rubygem-concurrent-ruby>=1.1<2:devel/rubygem-concurrent-ruby \
		rubygem-matrix>=0.4<1:math/rubygem-matrix \
		rubygem-prawn24>=2.4.0<2.5:print/rubygem-prawn24 \
		rubygem-prawn-icon3>=3.1.0<3.2:print/rubygem-prawn-icon3 \
		rubygem-prawn-svg036>=0.36.1<0.37:print/rubygem-prawn-svg036 \
		rubygem-prawn-table>=0.2.0<0.3:print/rubygem-prawn-table \
		rubygem-prawn-templates>=0.1.0<0.2:print/rubygem-prawn-templates \
		rubygem-treetop>=1.6.0<1.7:devel/rubygem-treetop \
		rubygem-ttfunk17>=1.7.0<1.8:print/rubygem-ttfunk17

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/asciidoctor-pdf \
		bin/asciidoctor-pdf-optimize

.include <bsd.port.mk>
