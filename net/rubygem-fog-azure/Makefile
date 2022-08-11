PORTNAME=	fog-azure
PORTVERSION=	0.0.2
PORTREVISION=	2
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support Microsoft Azure

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-azure>=0.6<1:net/rubygem-azure \
		rubygem-fog-core1>=1.27<2:devel/rubygem-fog-core1 \
		rubygem-fog-json>=1.0<2:devel/rubygem-fog-json \
		rubygem-fog-xml>=0.1<1:textproc/rubygem-fog-xml

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
