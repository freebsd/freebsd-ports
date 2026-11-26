PORTNAME=	http
PORTVERSION=	6.0.4
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple Ruby DSL for making HTTP requests
WWW=		https://github.com/httprb/http

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-http-cookie>=1.0<2:www/rubygem-http-cookie \
		rubygem-llhttp>=0.6.1<0.7:www/rubygem-llhttp

USES=		cpe gem

CPE_VENDOR=	http.rb_project
CPE_PRODUCT=	http.rb

NO_ARCH=	yes

.include <bsd.port.mk>
