# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	html2haml
PORTVERSION=	2.0.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	horia@racoviceanu.com
COMMENT=	Converts HTML into Haml

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-erubis>=2.7.0:www/rubygem-erubis \
		rubygem-haml>=4.0.0:www/rubygem-haml \
		rubygem-nokogiri>=1.6.0:textproc/rubygem-nokogiri \
		rubygem-ruby_parser>=3.5:devel/rubygem-ruby_parser

USE_RUBY=	yes
NO_ARCH=	yes

USES=		gem
PLIST_FILES=	bin/html2haml

.include <bsd.port.mk>
