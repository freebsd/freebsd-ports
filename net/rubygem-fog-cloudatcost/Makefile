# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fog-cloudatcost
PORTVERSION=	0.2.3
PORTREVISION=	1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support CloudAtCost

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-fog-core>=1.41:devel/rubygem-fog-core \
		rubygem-fog-json>=1.0:devel/rubygem-fog-json \
		rubygem-fog-xml>=0.1:textproc/rubygem-fog-xml \
		rubygem-ipaddress>=0.8:net/rubygem-ipaddress

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
