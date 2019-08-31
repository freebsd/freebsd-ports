# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fog-openstack
PORTVERSION=	1.0.9
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support OpenStack clouds

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-fog-core>=2.1:devel/rubygem-fog-core \
		rubygem-fog-json>=1.0:devel/rubygem-fog-json \
		rubygem-ipaddress>=0.8:net/rubygem-ipaddress

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
