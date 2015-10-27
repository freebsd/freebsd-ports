# $FreeBSD$

PORTNAME=	omniauth-oauth2
PORTVERSION=	1.4.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Abstract OAuth2 strategy for OmniAuth

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-oauth2>=1.0:${PORTSDIR}/net/rubygem-oauth2 \
		rubygem-omniauth>=1.2:${PORTSDIR}/security/rubygem-omniauth

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
