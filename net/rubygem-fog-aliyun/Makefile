# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fog-aliyun
PORTVERSION=	0.0.10
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support aliyun OSS/ECS

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-fog-core>=1.27:${PORTSDIR}/devel/rubygem-fog-core \
		rubygem-fog-json>=1.0:${PORTSDIR}/devel/rubygem-fog-json \
		rubygem-ipaddress>=0.8:${PORTSDIR}/net/rubygem-ipaddress \
		rubygem-xml-simple>=1.1:${PORTSDIR}/textproc/rubygem-xml-simple

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
