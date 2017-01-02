# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pdf-reader
PORTVERSION=	1.4.1
CATEGORIES=	print rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	PDF parser conforming as much as possible to the PDF specification

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-afm>=0.2.1:print/rubygem-afm \
		rubygem-ascii85>=1.0.0:devel/rubygem-ascii85 \
		rubygem-hashery>=2.0:devel/rubygem-hashery \
		rubygem-ruby-rc4>=0:security/rubygem-ruby-rc4 \
		rubygem-ttfunk>=0:print/rubygem-ttfunk

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/pdf_callbacks bin/pdf_list_callbacks bin/pdf_object bin/pdf_text

.include <bsd.port.mk>
