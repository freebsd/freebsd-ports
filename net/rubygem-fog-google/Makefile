# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	fog-google
PORTVERSION=	1.19.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support Google Cloud

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-fog-core210>=0<2.3:devel/rubygem-fog-core210 \
		rubygem-fog-json>=1.2<2:devel/rubygem-fog-json \
		rubygem-fog-xml>=0.1.0<0.2:textproc/rubygem-fog-xml \
		rubygem-google-apis-compute_v1>=0.14<1:devel/rubygem-google-apis-compute_v1 \
		rubygem-google-apis-dns_v1>=0.12<1:dns/rubygem-google-apis-dns_v1 \
		rubygem-google-apis-iamcredentials_v1>=0.6<1:devel/rubygem-google-apis-iamcredentials_v1 \
		rubygem-google-apis-monitoring_v3>=0.12<1:devel/rubygem-google-apis-monitoring_v3 \
		rubygem-google-apis-pubsub_v1>=0.7<1:devel/rubygem-google-apis-pubsub_v1 \
		rubygem-google-apis-sqladmin_v1beta4>=0.13<1:devel/rubygem-google-apis-sqladmin_v1beta4 \
		rubygem-google-apis-storage_v1>=0.6<1:devel/rubygem-google-apis-storage_v1 \
		rubygem-google-cloud-env>=1.2<2:net/rubygem-google-cloud-env

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

SHEBANG_FILES=	.github/scripts/setup_creds.sh

.include <bsd.port.mk>
