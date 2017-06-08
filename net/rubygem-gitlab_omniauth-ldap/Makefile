# $FreeBSD$

PORTNAME=	gitlab_omniauth-ldap
PORTVERSION=	2.0.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	LDAP strategy for OmniAuth

LICENSE=	MIT

RUN_DEPENDS=	rubygem-net-ldap>=0.16:net/rubygem-net-ldap \
		rubygem-omniauth13>=1.3.1:security/rubygem-omniauth13 \
		rubygem-pyu-ruby-sasl>=0.0.3.3:security/rubygem-pyu-ruby-sasl \
		rubygem-rubyntlm05>=0.5.2:net/rubygem-rubyntlm05

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
