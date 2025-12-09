PORTNAME=	google-cloud-spanner
PORTVERSION=	2.32.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Official library for Google Cloud Spanner API
WWW=		https://cloud.google.com/ruby/docs/reference/google-cloud-spanner/latest/ \
		https://googleapis.github.io/google-cloud-ruby/docs/ \
		https://github.com/googleapis/ruby-spanner

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-bigdecimal>=3.0<4:math/rubygem-bigdecimal \
		rubygem-concurrent-ruby>=1.0<2:devel/rubygem-concurrent-ruby \
		rubygem-google-cloud-core>=1.7<2:net/rubygem-google-cloud-core \
		rubygem-google-cloud-spanner-admin-database-v1>=1.4<2:net/rubygem-google-cloud-spanner-admin-database-v1 \
		rubygem-google-cloud-spanner-admin-instance-v1>=1.6<3:net/rubygem-google-cloud-spanner-admin-instance-v1 \
		rubygem-google-cloud-spanner-v1>=1.6<2:net/rubygem-google-cloud-spanner-v1

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
