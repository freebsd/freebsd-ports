PORTNAME=	fog-google
PORTVERSION=	1.23.0
PORTREVISION=	1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support Google Cloud
WWW=		https://github.com/fog/fog-google

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-addressable>=2.7.0:www/rubygem-addressable \
		rubygem-fog-core210>=0<2.3:devel/rubygem-fog-core210 \
		rubygem-fog-json>=1.2<2:devel/rubygem-fog-json \
		rubygem-fog-xml>=0.1.0<0.2:textproc/rubygem-fog-xml \
		rubygem-google-apis-compute_v1>=0.53<1:devel/rubygem-google-apis-compute_v1 \
		rubygem-google-apis-dns_v1>=0.28<1:dns/rubygem-google-apis-dns_v1 \
		rubygem-google-apis-iamcredentials_v1>=0.15<1:devel/rubygem-google-apis-iamcredentials_v1 \
		rubygem-google-apis-monitoring_v3>=0.37<1:devel/rubygem-google-apis-monitoring_v3 \
		rubygem-google-apis-pubsub_v1>=0.30<1:devel/rubygem-google-apis-pubsub_v1 \
		rubygem-google-apis-sqladmin_v1beta4>=0.38<1:devel/rubygem-google-apis-sqladmin_v1beta4 \
		rubygem-google-apis-storage_v1>=0.19<1:devel/rubygem-google-apis-storage_v1 \
		rubygem-google-cloud-env>=1.2<3.0:net/rubygem-google-cloud-env

USES=		gem shebangfix

NO_ARCH=	yes

SHEBANG_FILES=	.github/scripts/setup_creds.sh

.include <bsd.port.mk>
