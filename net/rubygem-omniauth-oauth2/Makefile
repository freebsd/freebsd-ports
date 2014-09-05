# $FreeBSD$

PORTNAME=	omniauth-oauth2
PORTVERSION=	1.2.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Abstract OAuth2 strategy for OmniAuth

RUN_DEPENDS=	rubygem-oauth2>=1.0:${PORTSDIR}/net/rubygem-oauth2 \
		rubygem-omniauth>=1.2:${PORTSDIR}/security/rubygem-omniauth \
		rubygem-multi_json>=1.3:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-faraday>=0.8.0:${PORTSDIR}/www/rubygem-faraday

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes


.include <bsd.port.mk>
