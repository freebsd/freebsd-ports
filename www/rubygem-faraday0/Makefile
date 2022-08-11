PORTNAME=	faraday
PORTVERSION=	0.17.5
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	0

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP/REST API client library in Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-multipart-post>=1.2<3:www/rubygem-multipart-post

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

CPE_VENDOR=	faraday_project

PORTSCOUT=	limit:^0\.

.include <bsd.port.mk>
