PORTNAME=	fog-vsphere
PORTVERSION=	3.5.2
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support vSphere
WWW=		https://github.com/fog/fog-vsphere

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-fog-core>=0:devel/rubygem-fog-core \
		rubygem-rbvmomi>=1.9<4:net/rubygem-rbvmomi

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
