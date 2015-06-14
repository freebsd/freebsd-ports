# $FreeBSD$

PORTNAME=	omniauth-oauth2
PORTVERSION=	1.3.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Abstract OAuth2 strategy for OmniAuth

LICENSE=	MIT

RUN_DEPENDS=	rubygem-oauth2>=1.0:${PORTSDIR}/net/rubygem-oauth2 \
		rubygem-omniauth>=1.2:${PORTSDIR}/security/rubygem-omniauth \
		rubygem-multi_json>=1.3:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-faraday>=0.8.0:${PORTSDIR}/www/rubygem-faraday

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
