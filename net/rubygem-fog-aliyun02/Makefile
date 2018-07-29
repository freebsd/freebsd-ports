# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fog-aliyun
PORTVERSION=	0.2.2
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	02

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support aliyun OSS/ECS

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-fog-core1>=1.27:devel/rubygem-fog-core1 \
		rubygem-fog-json>=1.0:devel/rubygem-fog-json \
		rubygem-ipaddress>=0.8:net/rubygem-ipaddress \
		rubygem-xml-simple>=1.1:textproc/rubygem-xml-simple

PORTSCOUT=	limit:^0\.2\.

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
