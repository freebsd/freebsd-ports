PORTNAME=	x-core
PORTVERSION=	1.0.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP layer of the X gem: authentication, requests, and errors
WWW=		https://github.com/sferik/x-ruby/tree/main/x-core \
		https://github.com/sferik/x-ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-net-http>=0.9.1<1:www/rubygem-net-http \
		rubygem-simple_oauth>=1.0<2:net/rubygem-simple_oauth

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
