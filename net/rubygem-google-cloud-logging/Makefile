PORTNAME=	google-cloud-logging
PORTVERSION=	2.6.1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Official library for Stackdriver Logging
WWW=		https://cloud.google.com/ruby/docs/reference/google-cloud-logging/latest/ \
		https://googleapis.github.io/google-cloud-ruby/docs/ \
		https://github.com/googleapis/google-cloud-ruby/tree/main/google-cloud-logging \
		https://github.com/googleapis/google-cloud-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-concurrent-ruby>=1.1<2:devel/rubygem-concurrent-ruby \
		rubygem-google-cloud-core>=1.5<2:net/rubygem-google-cloud-core \
		rubygem-google-cloud-logging-v2>=0.0<2.0:net/rubygem-google-cloud-logging-v2 \
		rubygem-stackdriver-core>=1.3<2:net/rubygem-stackdriver-core

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
