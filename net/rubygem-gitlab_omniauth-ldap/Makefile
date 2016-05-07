# $FreeBSD$

PORTNAME=	gitlab_omniauth-ldap
PORTVERSION=	1.2.1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	LDAP strategy for OmniAuth

LICENSE=	MIT

RUN_DEPENDS=	rubygem-net-ldap>=0.9:net/rubygem-net-ldap \
		rubygem-omniauth>=1.0:security/rubygem-omniauth \
		rubygem-pyu-ruby-sasl>=0.0.3.1:security/rubygem-pyu-ruby-sasl \
		rubygem-rubyntlm>=0.3:net/rubygem-rubyntlm

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
