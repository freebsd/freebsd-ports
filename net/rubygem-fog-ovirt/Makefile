PORTNAME=	fog-ovirt
PORTVERSION=	2.0.2
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support oVirt platform

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-activesupport60>=0:devel/rubygem-activesupport60 \
		rubygem-fog-core>=0:devel/rubygem-fog-core \
		rubygem-fog-json>=0:devel/rubygem-fog-json \
		rubygem-fog-xml>=0:textproc/rubygem-fog-xml \
		rubygem-ovirt-engine-sdk>=4.3.1:net/rubygem-ovirt-engine-sdk

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
