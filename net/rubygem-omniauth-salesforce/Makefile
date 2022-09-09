PORTNAME=	omniauth-salesforce
PORTVERSION=	1.0.5
PORTREVISION=	2
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	OmniAuth strategy for salesforce.com
WWW=		https://github.com/realdoug/omniauth-salesforce

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-omniauth>=1.0<3:security/rubygem-omniauth \
		rubygem-omniauth-oauth2>=1.0<2:net/rubygem-omniauth-oauth2

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
