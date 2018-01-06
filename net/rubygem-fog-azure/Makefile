# Created by: Torsten Zuehlsdorff <tz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fog-azure
PORTVERSION=	0.0.2
PORTREVISION=	1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support Microsoft Azure

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-azure>=0.6:net/rubygem-azure \
		rubygem-fog-core>=1.27:devel/rubygem-fog-core \
		rubygem-fog-json>=1.0:devel/rubygem-fog-json \
		rubygem-fog-xml>=0.1:textproc/rubygem-fog-xml

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
