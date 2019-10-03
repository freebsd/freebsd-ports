# $FreeBSD$

PORTNAME=	omniauth-oauth2
PORTVERSION=	1.5.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Abstract OAuth2 strategy for OmniAuth

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-oauth2>=1.1<2:net/rubygem-oauth2 \
		rubygem-omniauth>=1.2<2:security/rubygem-omniauth

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
