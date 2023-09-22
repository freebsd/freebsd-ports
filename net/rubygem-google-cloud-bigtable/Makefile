PORTNAME=	google-cloud-bigtable
PORTVERSION=	2.9.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Official library for Cloud Bigtable API
WWW=		https://github.com/googleapis/google-cloud-ruby/tree/main/google-cloud-bigtable

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-concurrent-ruby>=1.0<2:devel/rubygem-concurrent-ruby \
		rubygem-google-cloud-bigtable-admin-v2>=0.0<1:net/rubygem-google-cloud-bigtable-admin-v2 \
		rubygem-google-cloud-bigtable-v2>=0.14<1:net/rubygem-google-cloud-bigtable-v2 \
		rubygem-google-cloud-core>=1.5<2:net/rubygem-google-cloud-core

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
