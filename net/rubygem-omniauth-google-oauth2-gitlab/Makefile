PORTNAME=	omniauth-google-oauth2
PORTVERSION=	1.2.1
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Google OAuth2 strategy for OmniAuth 1.x
WWW=		https://github.com/zquestz/omniauth-google-oauth2

LICENSE=	MIT

RUN_DEPENDS=	rubygem-jwt>=2.9.2:www/rubygem-jwt \
		rubygem-oauth2-gitlab>=2.0<3:net/rubygem-oauth2-gitlab \
		rubygem-omniauth-gl>=2.0<3:security/rubygem-omniauth-gl \
		rubygem-omniauth-oauth2-gitlab>=1.8<2:net/rubygem-omniauth-oauth2-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
