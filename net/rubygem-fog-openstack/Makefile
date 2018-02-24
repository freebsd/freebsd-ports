# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fog-openstack
PORTVERSION=	0.1.24
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support OpenStack clouds

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-fog-core1>=1.40:devel/rubygem-fog-core1 \
		rubygem-fog-json102>=1.0:devel/rubygem-fog-json102 \
		rubygem-ipaddress>=0.8:net/rubygem-ipaddress

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
