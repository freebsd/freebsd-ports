# $FreeBSD$

PORTNAME=	gitlab_omniauth-ldap
PORTVERSION=	1.0.3
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A LDAP strategy for OmniAuth.

RUN_DEPENDS=	rubygem-net-ldap>=0.3.1:${PORTSDIR}/net/rubygem-net-ldap \
		rubygem-omniauth>=1.0:${PORTSDIR}/security/rubygem-omniauth \
		rubygem-pyu-ruby-sasl>=0.0.3.1:${PORTSDIR}/security/rubygem-pyu-ruby-sasl \
		rubygem-rubyntlm>=0.1.1:${PORTSDIR}/net/rubygem-rubyntlm

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes


.include <bsd.port.mk>
