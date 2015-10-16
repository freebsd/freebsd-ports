# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fog-brightbox
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support Brightbox Cloud

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-fog-core>=1.22:${PORTSDIR}/devel/rubygem-fog-core \
		rubygem-fog-json>=0:${PORTSDIR}/devel/rubygem-fog-json \
		rubygem-inflecto>=0.0.2:${PORTSDIR}/devel/rubygem-inflecto

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
