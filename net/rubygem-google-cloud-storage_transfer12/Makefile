PORTNAME=	google-cloud-storage_transfer
PORTVERSION=	1.2.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	12

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Official library for Google Cloud Storage Transfer
WWW=		https://github.com/googleapis/google-cloud-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-google-cloud-core>=1.6<2:net/rubygem-google-cloud-core \
		rubygem-google-cloud-storage_transfer-v1>=0.5<2:net/rubygem-google-cloud-storage_transfer-v1

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^1\.2\.

.include <bsd.port.mk>
