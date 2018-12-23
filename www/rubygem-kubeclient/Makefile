# $FreeBSD$

PORTNAME=	kubeclient
PORTVERSION=	4.0.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Client for Kubernetes REST API

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-http>=3.0.0:www/rubygem-http \
		rubygem-recursive-open-struct>=1.0.4:devel/rubygem-recursive-open-struct \
		rubygem-rest-client>=2.0:www/rubygem-rest-client

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
