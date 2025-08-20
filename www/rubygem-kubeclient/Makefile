PORTNAME=	kubeclient
PORTVERSION=	4.12.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Client for Kubernetes REST API
WWW=		https://github.com/abonas/kubeclient

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-http4>=3.0<6.0:www/rubygem-http4 \
		rubygem-jsonpath>=1.0<2:devel/rubygem-jsonpath \
		rubygem-recursive-open-struct1>=1.1.1<2.0:devel/rubygem-recursive-open-struct1 \
		rubygem-rest-client-gitlab>=2.0<3:www/rubygem-rest-client-gitlab

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	redhat

.include <bsd.port.mk>
