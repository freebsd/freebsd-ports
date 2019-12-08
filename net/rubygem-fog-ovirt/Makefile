# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fog-ovirt
PORTVERSION=	1.2.3
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support oVirt platform

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-fog-core>=0:devel/rubygem-fog-core \
		rubygem-fog-json>=0:devel/rubygem-fog-json \
		rubygem-fog-xml>=0:textproc/rubygem-fog-xml \
		rubygem-ovirt-engine-sdk>=4.1.3:net/rubygem-ovirt-engine-sdk \
		rubygem-rbovirt>=0.1.5<0.2:www/rubygem-rbovirt

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
