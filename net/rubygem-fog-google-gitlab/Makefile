PORTNAME=	fog-google
PORTVERSION=	1.25.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support Google Cloud
WWW=		https://github.com/fog/fog-google

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-addressable>=2.7.0:www/rubygem-addressable \
		rubygem-fog-core-gitlab>=2.5<3:devel/rubygem-fog-core-gitlab \
		rubygem-fog-json-gitlab>=1.2<2:devel/rubygem-fog-json-gitlab \
		rubygem-fog-xml-gitlab>=0.1.0<0.2:textproc/rubygem-fog-xml-gitlab \
		rubygem-google-apis-compute_v1-gitlab>=0.53<1:devel/rubygem-google-apis-compute_v1-gitlab \
		rubygem-google-apis-dns_v1-gitlab>=0.28<1:dns/rubygem-google-apis-dns_v1-gitlab \
		rubygem-google-apis-iamcredentials_v1-gitlab>=0.15<1:devel/rubygem-google-apis-iamcredentials_v1-gitlab \
		rubygem-google-apis-monitoring_v3-gitlab>=0.37<1:devel/rubygem-google-apis-monitoring_v3-gitlab \
		rubygem-google-apis-pubsub_v1-gitlab>=0.30<1:devel/rubygem-google-apis-pubsub_v1-gitlab \
		rubygem-google-apis-sqladmin_v1beta4-gitlab>=0.38<1:devel/rubygem-google-apis-sqladmin_v1beta4-gitlab \
		rubygem-google-apis-storage_v1-gitlab>=0.19<1:devel/rubygem-google-apis-storage_v1-gitlab \
		rubygem-google-cloud-env-gitlab>=1.2<3.0:net/rubygem-google-cloud-env-gitlab

USES=		gem shebangfix

SHEBANG_FILES=	.github/scripts/setup_creds.sh

NO_ARCH=	yes

.include <bsd.port.mk>
