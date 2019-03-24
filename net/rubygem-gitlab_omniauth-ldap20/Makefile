# $FreeBSD$

PORTNAME=	gitlab_omniauth-ldap
PORTVERSION=	2.0.4
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	20

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	LDAP strategy for OmniAuth

LICENSE=	MIT

DEPRECATED=	Use net/rubygem-gitlab_omniauth-ldap instead
EXPIRATION_DATE=2019-03-31

RUN_DEPENDS=	rubygem-net-ldap>=0.16:net/rubygem-net-ldap \
		rubygem-omniauth>=1.3:security/rubygem-omniauth \
		rubygem-pyu-ruby-sasl>=0.0.3.3:security/rubygem-pyu-ruby-sasl \
		rubygem-rubyntlm>=0.5:net/rubygem-rubyntlm

PORTSCOUT=	limit:^2\.0\.

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
