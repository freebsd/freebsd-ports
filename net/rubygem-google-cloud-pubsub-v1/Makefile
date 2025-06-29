PORTNAME=	google-cloud-pubsub-v1
PORTVERSION=	1.10.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby Client for the Cloud Pub/Sub V1 API
WWW=		https://cloud.google.com/ruby/docs/reference/google-cloud-pubsub-v1/latest/ \
		https://github.com/googleapis/google-cloud-ruby/tree/main/google-cloud-pubsub-v1 \
		https://github.com/googleapis/google-cloud-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-gapic-common>=1.0<2:devel/rubygem-gapic-common \
		rubygem-google-cloud-errors>=1.0<2:net/rubygem-google-cloud-errors \
		rubygem-google-iam-v1>=1.3<2:devel/rubygem-google-iam-v1

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
