PORTNAME=	fog-vsphere
PORTVERSION=	3.7.3
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support vSphere
WWW=		https://github.com/fog/fog-vsphere

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-base64>=0:converters/rubygem-base64 \
		rubygem-fog-core>=0:devel/rubygem-fog-core \
		rubygem-ostruct>=0:devel/rubygem-ostruct \
		rubygem-rbvmomi2>=3.0<4:net/rubygem-rbvmomi2

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
