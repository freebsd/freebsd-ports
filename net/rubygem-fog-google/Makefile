# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	fog-google
PORTVERSION=	1.13.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support Google Cloud

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-fog-core210>=0:devel/rubygem-fog-core210 \
		rubygem-fog-json>=1.2<2:devel/rubygem-fog-json \
		rubygem-fog-xml>=0.1.0<0.2:textproc/rubygem-fog-xml \
		rubygem-google-api-client>=0.44.2:devel/rubygem-google-api-client \
		rubygem-google-cloud-env>=1.2<2:net/rubygem-google-cloud-env

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
