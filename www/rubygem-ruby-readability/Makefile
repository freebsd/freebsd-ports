PORTNAME=	ruby-readability
PORTVERSION=	0.7.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Readability for Ruby
WWW=		https://github.com/cantino/ruby-readability

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-guess_html_encoding>=0.0.4:devel/rubygem-guess_html_encoding \
		rubygem-nokogiri>=1.6.0:textproc/rubygem-nokogiri

NO_ARCH=	yes
USES=		gem

PLIST_FILES=	bin/readability

.include <bsd.port.mk>
