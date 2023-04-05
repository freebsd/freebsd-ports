PORTNAME=	fog-aliyun
PORTVERSION=	0.4.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support aliyun OSS/ECS
WWW=		https://github.com/fog/fog-aliyun

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-addressable>=2.8.0<2.9:www/rubygem-addressable \
		rubygem-aliyun-sdk>=0.8.0<0.9:devel/rubygem-aliyun-sdk \
		rubygem-fog-core>=0:devel/rubygem-fog-core \
		rubygem-fog-json>=0:devel/rubygem-fog-json \
		rubygem-ipaddress>=0.8<1:net/rubygem-ipaddress \
		rubygem-xml-simple>=1.1<2:textproc/rubygem-xml-simple

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
