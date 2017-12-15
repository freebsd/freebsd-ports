# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	omniauth-oauth2-generic
PORTVERSION=	0.2.4
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generic, Configurable OmniAuth Strategy for OAuth2 providers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-omniauth-oauth2>=1.0:net/rubygem-omniauth-oauth2

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/console ${STAGEDIR}${PREFIX}/bin/setup

.include <bsd.port.mk>
