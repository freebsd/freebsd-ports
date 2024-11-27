PORTNAME=	net-http
PORTVERSION=	0.4.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	041

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP client api for Ruby
WWW=		https://github.com/ruby/net-http

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-uri>=0:net/rubygem-uri

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	ignore:1

.include <bsd.port.mk>
