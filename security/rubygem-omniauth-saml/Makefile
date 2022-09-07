PORTNAME=	omniauth-saml
PORTVERSION=	2.1.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	OmniAuth strategy for SAML
WWW=		https://github.com/omniauth/omniauth-saml

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-omniauth>=2.0<3:security/rubygem-omniauth \
		rubygem-ruby-saml>=1.12<2:security/rubygem-ruby-saml

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
