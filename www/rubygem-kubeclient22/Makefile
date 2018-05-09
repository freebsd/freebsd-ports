# $FreeBSD$

PORTNAME=	kubeclient
PORTVERSION=	2.2.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	22

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Client for Kubernetes REST API

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-http>=0.9.8:www/rubygem-http \
		rubygem-recursive-open-struct100=1.0.0:devel/rubygem-recursive-open-struct100 \
		rubygem-rest-client>=0:www/rubygem-rest-client

PORTSCOUT=	limit:^2\.2

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
