PORTNAME=	google-cloud-storage_transfer
PORTVERSION=	1.5.1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Official library for Google Cloud Storage Transfer
WWW=		https://cloud.google.com/ruby/docs/reference/google-cloud-storage_transfer/latest \
		https://googleapis.github.io/google-cloud-ruby/docs/ \
		https://github.com/googleapis/google-cloud-ruby/tree/main/google-cloud-storage_transfer \
		https://github.com/googleapis/google-cloud-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-google-cloud-core>=1.6<2:net/rubygem-google-cloud-core \
		rubygem-google-cloud-storage_transfer-v1>=0.9<2:net/rubygem-google-cloud-storage_transfer-v1

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
