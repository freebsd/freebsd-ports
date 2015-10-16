# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fog-dynect
PORTVERSION=	0.0.2
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support Dynect DNS

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-fog-core>=0:${PORTSDIR}/devel/rubygem-fog-core \
		rubygem-fog-json>=0:${PORTSDIR}/devel/rubygem-fog-json \
		rubygem-fog-xml>=0:${PORTSDIR}/textproc/rubygem-fog-xml

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
