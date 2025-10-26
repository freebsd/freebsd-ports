PORTNAME=	faraday
PORTVERSION=	2.13.4
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	HTTP/REST API client library in Ruby
WWW=		https://github.com/lostisland/faraday

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-faraday-net_http-gitlab>=2.0<3.5:www/rubygem-faraday-net_http-gitlab \
		rubygem-json-gitlab>=0:devel/rubygem-json-gitlab \
		rubygem-logger-gitlab>=0:devel/rubygem-logger-gitlab

USES=		cpe gem

CPE_VENDOR=	faraday_project

NO_ARCH=	yes

.include <bsd.port.mk>
