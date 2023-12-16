PORTNAME=	google-cloud-monitoring-v3
PORTVERSION=	0.13.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby Client for the Cloud Monitoring V3 API
WWW=		https://cloud.google.com/ruby/docs/reference/google-cloud-monitoring-v3/latest/ \
		https://googleapis.github.io/google-cloud-ruby/docs/ \
		https://github.com/googleapis/google-cloud-ruby/tree/main/google-cloud-monitoring-v3 \
		https://github.com/googleapis/google-cloud-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-gapic-common>=0.20.0<2.0:devel/rubygem-gapic-common \
		rubygem-google-cloud-errors>=1.0<2:net/rubygem-google-cloud-errors

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
