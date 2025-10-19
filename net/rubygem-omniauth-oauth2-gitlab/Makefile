PORTNAME=	omniauth-oauth2
PORTVERSION=	1.8.0
PORTREVISION=	1
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Abstract OAuth2 strategy for OmniAuth
WWW=		https://github.com/omniauth/omniauth-oauth2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-oauth2-gitlab>=1.4<3:net/rubygem-oauth2-gitlab \
		rubygem-omniauth-gl>=1.9<3:security/rubygem-omniauth-gl

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
