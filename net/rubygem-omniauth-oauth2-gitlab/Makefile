PORTNAME=	omniauth-oauth2
PORTVERSION=	1.9.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Abstract OAuth2 strategy for OmniAuth
WWW=		https://github.com/omniauth/omniauth-oauth2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-oauth2-gitlab>=2.0.2<3:net/rubygem-oauth2-gitlab \
		rubygem-omniauth-gl>=2.0<3:security/rubygem-omniauth-gl

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
