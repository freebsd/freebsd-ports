# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fog-ovirt
PORTVERSION=	1.0.1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support oVirt platform

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-fog-core1>=1.45:devel/rubygem-fog-core1 \
		rubygem-fog-json>=0:devel/rubygem-fog-json \
		rubygem-fog-xml>=0.1.1:textproc/rubygem-fog-xml \
		rubygem-rbovirt>=0.1.5:www/rubygem-rbovirt

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
