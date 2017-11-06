# $FreeBSD$

PORTNAME=	kubeclient
PORTVERSION=	2.4.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Client for Kubernetes REST API

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-http>=0.9.8:www/rubygem-http \
		rubygem-recursive-open-struct>=1.0.0:devel/rubygem-recursive-open-struct \
		rubygem-rest-client>=0:www/rubygem-rest-client

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
