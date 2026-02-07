PORTNAME=	html2haml
PORTVERSION=	2.3.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Converts HTML into Haml
WWW=		https://haml.info/ \
		https://github.com/haml/html2haml

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-erubis>=2.7.0<2.8:www/rubygem-erubis \
		rubygem-haml5>=4.0:www/rubygem-haml5 \
		rubygem-nokogiri>=1.6.0:textproc/rubygem-nokogiri \
		rubygem-ruby_parser>=3.5<4:devel/rubygem-ruby_parser

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/html2haml

.include <bsd.port.mk>
