# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fog-aws
PORTVERSION=	3.6.5
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support Amazon Web Services

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-fog-core>=2.1<3:devel/rubygem-fog-core \
		rubygem-fog-json>=1.1<2:devel/rubygem-fog-json \
		rubygem-fog-xml>=0.1<1:textproc/rubygem-fog-xml \
		rubygem-ipaddress>=0.8<1:net/rubygem-ipaddress

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/console ${STAGEDIR}${PREFIX}/bin/setup

.include <bsd.port.mk>
