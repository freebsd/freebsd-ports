PORTNAME=	google-cloud-pubsub
PORTVERSION=	2.23.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Official library for Google Cloud Pub/Sub
WWW=		https://cloud.google.com/ruby/docs/reference/google-cloud-pubsub/latest/ \
		https://googleapis.github.io/google-cloud-ruby/docs/ \
		https://github.com/googleapis/google-cloud-ruby/tree/main/google-cloud-pubsub \
		https://github.com/googleapis/google-cloud-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-concurrent-ruby>=1.3<2:devel/rubygem-concurrent-ruby \
		rubygem-google-cloud-core>=1.8<2:net/rubygem-google-cloud-core \
		rubygem-google-cloud-pubsub-v1>=1.11<2:net/rubygem-google-cloud-pubsub-v1 \
		rubygem-retriable>=3.1<4:devel/rubygem-retriable

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
