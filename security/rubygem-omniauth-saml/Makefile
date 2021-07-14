# Created by: Torsten Zuhlsdorff <ports@toco-domains.de>

PORTNAME=	omniauth-saml
PORTVERSION=	1.10.1
PORTREVISION=	1
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	OmniAuth strategy for SAML

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-omniauth1>=1.3.2<2:security/rubygem-omniauth1 \
		rubygem-ruby-saml>=1.7<2:security/rubygem-ruby-saml

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
