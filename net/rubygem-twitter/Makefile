# Created by: ijliao
# $FreeBSD$

PORTNAME=	twitter
PORTVERSION=	6.2.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby interface to the Twitter API

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-addressable>=2.3:www/rubygem-addressable \
		rubygem-buftok>=0.2.0:devel/rubygem-buftok \
		rubygem-equalizer>=0.0.11:devel/rubygem-equalizer \
		rubygem-http>=3.0:www/rubygem-http \
		rubygem-http-form_data>=2.0:www/rubygem-http-form_data \
		rubygem-http_parser.rb>=0.6.0:net/rubygem-http_parser.rb \
		rubygem-memoizable>=0.4.0:devel/rubygem-memoizable \
		rubygem-multipart-post>=2.0:www/rubygem-multipart-post \
		rubygem-naught>=1.0:devel/rubygem-naught \
		rubygem-simple_oauth>=0.3.0:net/rubygem-simple_oauth

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
