PORTNAME=	omniauth-oauth2
PORTVERSION=	1.7.3
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-v1

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Abstract OAuth2 strategy for OmniAuth

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-oauth2>=1.4<3:net/rubygem-oauth2 \
		rubygem-omniauth>=1.9<3:security/rubygem-omniauth

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
