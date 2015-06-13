# $FreeBSD$

PORTNAME=	omniauth-bitbucket
PORTVERSION=	0.0.2
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	OmniAuth strategy for Bitbucket

LICENSE=	MIT

RUN_DEPENDS=	rubygem-multi_json>=1.7:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-omniauth>=1.1:${PORTSDIR}/security/rubygem-omniauth \
		rubygem-omniauth-oauth>=1.0:${PORTSDIR}/net/rubygem-omniauth-oauth

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
