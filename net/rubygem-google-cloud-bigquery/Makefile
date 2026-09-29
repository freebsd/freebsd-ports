PORTNAME=	google-cloud-bigquery
PORTVERSION=	1.64.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sanpei@FreeBSD.org
COMMENT=	Official Ruby library for Google BigQuery
WWW=		https://docs.cloud.google.com/ruby/docs/reference/google-cloud-bigquery/latest \
		https://googleapis.github.io/google-cloud-ruby/docs/ \
		https://github.com/googleapis/google-cloud-ruby/tree/main/google-cloud-bigquery \
		https://github.com/googleapis/google-cloud-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-bigdecimal>=3.0<5:math/rubygem-bigdecimal \
		rubygem-concurrent-ruby>=1.0<2:devel/rubygem-concurrent-ruby \
		rubygem-google-apis-bigquery_v2>=0.71<1:devel/rubygem-google-apis-bigquery_v2 \
		rubygem-google-apis-core>=0.18<2:devel/rubygem-google-apis-core \
		rubygem-google-cloud-core>=1.6<2:net/rubygem-google-cloud-core \
		rubygem-googleauth>=1.9<2:security/rubygem-googleauth \
		rubygem-mini_mime>=1.0<2:mail/rubygem-mini_mime

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
