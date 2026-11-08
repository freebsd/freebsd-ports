PORTNAME=	google-cloud-resource_manager
PORTVERSION=	1.2.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Official library for Google Cloud Resource Manager
WWW=		https://docs.cloud.google.com/ruby/docs/reference/google-cloud-resource_manager/latest \
		https://googleapis.github.io/google-cloud-ruby/docs/ \
		https://github.com/googleapis/google-cloud-ruby/tree/main/google-cloud-resource_manager \
		https://github.com/googleapis/google-cloud-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-google-cloud-core>=1.6<2:net/rubygem-google-cloud-core \
		rubygem-google-cloud-resource_manager-v3>=1.2<2:net/rubygem-google-cloud-resource_manager-v3

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
