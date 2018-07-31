# $FreeBSD$

PORTNAME=	gitlab_omniauth-ldap
PORTVERSION=	2.0.4
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	20

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	LDAP strategy for OmniAuth

LICENSE=	MIT

RUN_DEPENDS=	rubygem-net-ldap>=0.16:net/rubygem-net-ldap \
		rubygem-omniauth>=1.3:security/rubygem-omniauth \
		rubygem-pyu-ruby-sasl>=0.0.3.3:security/rubygem-pyu-ruby-sasl \
		rubygem-rubyntlm>=0.5:net/rubygem-rubyntlm

PORTSCOUT=	limit:^2\.0\.

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
