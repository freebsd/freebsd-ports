# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fog-aliyun
PORTVERSION=	0.3.10
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support aliyun OSS/ECS

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-fog-core>=0:devel/rubygem-fog-core \
		rubygem-fog-json>=0:devel/rubygem-fog-json \
		rubygem-ipaddress>=0.8<1:net/rubygem-ipaddress \
		rubygem-xml-simple>=1.1<2:textproc/rubygem-xml-simple

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
