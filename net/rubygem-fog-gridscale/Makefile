# $FreeBSD$

PORTNAME=	fog-gridscale
PORTVERSION=	0.1.5
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support gridscale

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-fog-core>=2.1:devel/rubygem-fog-core \
		rubygem-fog-json>=1.2:devel/rubygem-fog-json \
		rubygem-ipaddress>=0.8:net/rubygem-ipaddress \
		rubygem-json>=2.1:devel/rubygem-json

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
