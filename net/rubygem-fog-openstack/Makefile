PORTNAME=	fog-openstack
PORTVERSION=	1.1.3
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support OpenStack clouds
WWW=		https://github.com/fog/fog-openstack

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-fog-core>=2.1<3:devel/rubygem-fog-core \
		rubygem-fog-json>=1.0:devel/rubygem-fog-json

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
