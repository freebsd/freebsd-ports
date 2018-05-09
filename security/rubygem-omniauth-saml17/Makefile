# $FreeBSD$

PORTNAME=	omniauth-saml
PORTVERSION=	1.7.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	17

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	OmniAuth strategy for SAML

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-omniauth>=1.3:security/rubygem-omniauth \
		rubygem-ruby-saml>=1.4:security/rubygem-ruby-saml

PORTSCOUT=	limit:^1\.7

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
