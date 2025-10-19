PORTNAME=	omniauth-saml
PORTVERSION=	2.2.4
PORTREVISION=	1
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	OmniAuth strategy for SAML
WWW=		https://github.com/omniauth/omniauth-saml

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-omniauth-gl>=2.1<3:security/rubygem-omniauth-gl \
		rubygem-ruby-saml-gitlab>=1.18<2:security/rubygem-ruby-saml-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
