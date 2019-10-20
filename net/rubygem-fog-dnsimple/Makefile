# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fog-dnsimple
PORTVERSION=	2.1.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support DNSimple

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-fog-core>=1.38<3:devel/rubygem-fog-core \
		rubygem-fog-json>=0:devel/rubygem-fog-json

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/console ${STAGEDIR}${PREFIX}/bin/setup

.include <bsd.port.mk>
