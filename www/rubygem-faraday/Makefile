PORTNAME=	faraday
PORTVERSION=	2.10.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP/REST API client library in Ruby
WWW=		https://github.com/lostisland/faraday

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-faraday-net_http>=2.0<3.3:www/rubygem-faraday-net_http \
		rubygem-logger>=0:devel/rubygem-logger

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	faraday_project

.include <bsd.port.mk>
