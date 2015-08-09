# Created by: Torsten Zühlsdorff <ports@toco-domains.de>
# $FreeBSD$

PORTNAME=	omniauth-saml
PORTVERSION=	1.3.1
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	OmniAuth strategy for SAML

LICENSE=	MIT

RUN_DEPENDS=	rubygem-omniauth>=1.1:${PORTSDIR}/security/rubygem-omniauth \
		rubygem-ruby-saml>=0.8.1:${PORTSDIR}/security/rubygem-ruby-saml

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
