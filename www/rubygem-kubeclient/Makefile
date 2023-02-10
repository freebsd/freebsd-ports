PORTNAME=	kubeclient
PORTVERSION=	4.9.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Client for Kubernetes REST API
WWW=		https://github.com/abonas/kubeclient

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-http4>=3.0<5.0:www/rubygem-http4 \
		rubygem-jsonpath>=1.0<2:devel/rubygem-jsonpath \
		rubygem-recursive-open-struct>=1.1.1<2.0:devel/rubygem-recursive-open-struct \
		rubygem-rest-client>=2.0<3:www/rubygem-rest-client

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	redhat

.include <bsd.port.mk>
