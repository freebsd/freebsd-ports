PORTNAME=	http
PORTVERSION=	3.3.0
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	3

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple Ruby DSL for making HTTP requests

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-addressable>=2.3<3:www/rubygem-addressable \
		rubygem-http-cookie>=1.0<2:www/rubygem-http-cookie \
		rubygem-http-form_data>=2.0<3:www/rubygem-http-form_data \
		rubygem-http_parser.rb>=0.6.0<1:net/rubygem-http_parser.rb

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^3\.

.include <bsd.port.mk>
