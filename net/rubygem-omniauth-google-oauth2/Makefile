# $FreeBSD$

PORTNAME=	omniauth-google-oauth2
PORTVERSION=	0.2.7
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Google OAuth2 strategy for OmniAuth 1.x

LICENSE=	MIT

RUN_DEPENDS=	rubygem-addressable>=2.3:${PORTSDIR}/www/rubygem-addressable \
		rubygem-jwt>=1.0:${PORTSDIR}/www/rubygem-jwt \
		rubygem-multi_json>=1.3:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-omniauth-oauth2>=1.1.1:${PORTSDIR}/net/rubygem-omniauth-oauth2 \
		rubygem-omniauth>=1.1.1:${PORTSDIR}/security/rubygem-omniauth

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
