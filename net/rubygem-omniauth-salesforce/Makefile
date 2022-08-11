PORTNAME=	omniauth-salesforce
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	OmniAuth strategy for salesforce.com

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-omniauth1>=1.0<2:security/rubygem-omniauth1 \
		rubygem-omniauth-oauth2>=1.0<2:net/rubygem-omniauth-oauth2

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
