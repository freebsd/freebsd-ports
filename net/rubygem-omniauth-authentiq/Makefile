# $FreeBSD$

PORTNAME=	omniauth-authentiq
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Authentiq OAuth2 Strategy for OmniAuth

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-jwt>=1.5:www/rubygem-jwt \
		rubygem-omniauth-oauth2>=1.5:net/rubygem-omniauth-oauth2

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
