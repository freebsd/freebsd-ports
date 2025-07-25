PORTNAME=	google-cloud-bigtable-v2
PORTVERSION=	1.8.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby Client for the Cloud Bigtable V2 API
WWW=		https://cloud.google.com/ruby/docs/reference/google-cloud-bigtable-v2/latest/ \
		https://github.com/googleapis/google-cloud-ruby/tree/main/google-cloud-bigtable-v2 \
		https://github.com/googleapis/google-cloud-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-gapic-common>=1.0<2:devel/rubygem-gapic-common \
		rubygem-google-cloud-errors>=1.0<2:net/rubygem-google-cloud-errors

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
