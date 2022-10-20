PORTNAME=	omniauth-google-oauth2
PORTVERSION=	1.0.1
PORTREVISION=	0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Google OAuth2 strategy for OmniAuth 1.x
WWW=		https://github.com/zquestz/omniauth-google-oauth2

LICENSE=	MIT

RUN_DEPENDS=	rubygem-jwt>=2.0:www/rubygem-jwt \
		rubygem-oauth2>=1.1<2:net/rubygem-oauth2 \
		rubygem-omniauth>=2.0<3:security/rubygem-omniauth \
		rubygem-omniauth-oauth2>=1.7.1<1.8:net/rubygem-omniauth-oauth2

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
