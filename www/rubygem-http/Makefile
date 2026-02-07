PORTNAME=	http
PORTVERSION=	5.3.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple Ruby DSL for making HTTP requests
WWW=		https://github.com/httprb/http

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-addressable>=2.8<3:www/rubygem-addressable \
		rubygem-http-cookie>=1.0<2:www/rubygem-http-cookie \
		rubygem-http-form_data>=2.2<3:www/rubygem-http-form_data \
		rubygem-llhttp-ffi>=0.5.0<0.6:www/rubygem-llhttp-ffi

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
