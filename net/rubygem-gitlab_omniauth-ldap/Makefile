PORTNAME=	gitlab_omniauth-ldap
PORTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	LDAP strategy for OmniAuth

LICENSE=	MIT

RUN_DEPENDS=	rubygem-net-ldap>=0.16<1:net/rubygem-net-ldap \
		rubygem-omniauth1>=1.3<2:security/rubygem-omniauth1 \
		rubygem-pyu-ruby-sasl>=0.0.3.3<1:security/rubygem-pyu-ruby-sasl \
		rubygem-rubyntlm>=0.5<1:net/rubygem-rubyntlm

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
