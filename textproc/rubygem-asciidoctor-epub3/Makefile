PORTNAME=	asciidoctor-epub3
PORTVERSION=	1.5.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Convert AsciiDoc documents to EPUB3

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-asciidoctor>=1.5.6<3:textproc/rubygem-asciidoctor \
		rubygem-mime-types>=3.0:misc/rubygem-mime-types \
		rubygem-gepub>=1.0.0:textproc/rubygem-gepub

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/asciidoctor-epub3 \
		bin/adb-push-ebook

.include <bsd.port.mk>
