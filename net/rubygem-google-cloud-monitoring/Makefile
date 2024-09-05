PORTNAME=	google-cloud-monitoring
PORTVERSION=	1.8.3
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby Client for the Cloud Monitoring API
WWW=		https://cloud.google.com/ruby/docs/reference/google-cloud-monitoring/latest/ \
		https://googleapis.github.io/google-cloud-ruby/docs/ \
		https://github.com/googleapis/google-cloud-ruby/tree/main/google-cloud-monitoring \
		https://github.com/googleapis/google-cloud-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-google-cloud-core>=1.6<2:net/rubygem-google-cloud-core \
		rubygem-google-cloud-monitoring-dashboard-v1>=0.14<2.0:net/rubygem-google-cloud-monitoring-dashboard-v1 \
		rubygem-google-cloud-monitoring-metrics_scope-v1>=0.5<2.0:net/rubygem-google-cloud-monitoring-metrics_scope-v1 \
		rubygem-google-cloud-monitoring-v3>=0.15<2.0:net/rubygem-google-cloud-monitoring-v3

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
