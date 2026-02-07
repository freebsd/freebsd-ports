PORTNAME=	fog-aliyun
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support aliyun OSS/ECS
WWW=		https://github.com/fog/fog-aliyun

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-addressable>=2.8.0<2.9:www/rubygem-addressable \
		rubygem-aliyun-sdk-gitlab>=0.8.0<0.9:devel/rubygem-aliyun-sdk-gitlab \
		rubygem-fog-core-gitlab>=0:devel/rubygem-fog-core-gitlab \
		rubygem-fog-json-gitlab>=0:devel/rubygem-fog-json-gitlab \
		rubygem-ipaddress>=0.8<1:net/rubygem-ipaddress \
		rubygem-xml-simple-gitlab>=1.1<2:textproc/rubygem-xml-simple-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
