# $FreeBSD$

PORTNAME=	kubeclient
PORTVERSION=	4.4.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Client for Kubernetes REST API

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-http3>=3.0.0<4.0:www/rubygem-http3 \
		rubygem-recursive-open-struct>=1.0.4<2.0:devel/rubygem-recursive-open-struct \
		rubygem-rest-client>=2.0<3.0:www/rubygem-rest-client

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
