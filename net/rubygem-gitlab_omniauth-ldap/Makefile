# $FreeBSD$

PORTNAME=	gitlab_omniauth-ldap
PORTVERSION=	2.1.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	LDAP strategy for OmniAuth

LICENSE=	MIT

RUN_DEPENDS=	rubygem-net-ldap>=0.16:net/rubygem-net-ldap \
		rubygem-omniauth>=1.3:security/rubygem-omniauth \
		rubygem-pyu-ruby-sasl>=0.0.3.3:security/rubygem-pyu-ruby-sasl \
		rubygem-rubyntlm>=0.5:net/rubygem-rubyntlm

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
