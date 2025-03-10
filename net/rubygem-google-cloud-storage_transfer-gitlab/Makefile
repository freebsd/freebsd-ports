PORTNAME=	google-cloud-storage_transfer
PORTVERSION=	1.2.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Official library for Google Cloud Storage Transfer
WWW=		https://github.com/googleapis/google-cloud-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-google-cloud-core-gitlab>=1.6<2:net/rubygem-google-cloud-core-gitlab \
		rubygem-google-cloud-storage_transfer-v1-gitlab>=0.5<2:net/rubygem-google-cloud-storage_transfer-v1-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
