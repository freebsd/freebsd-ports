PORTNAME=	pdf-reader
PORTVERSION=	2.14.1
PORTREVISION=	1
CATEGORIES=	print rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	PDF parser conforming as much as possible to the PDF specification
WWW=		https://github.com/yob/pdf-reader

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-afm0>=0.2.1<0.3:print/rubygem-afm0 \
		rubygem-ascii85>=1.0<3.0:devel/rubygem-ascii85 \
		rubygem-hashery>=2.0<3:devel/rubygem-hashery \
		rubygem-ruby-rc4>=0:security/rubygem-ruby-rc4 \
		rubygem-ttfunk>=0:print/rubygem-ttfunk

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/pdf_callbacks bin/pdf_object bin/pdf_text

.include <bsd.port.mk>
