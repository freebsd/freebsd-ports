PORTNAME=	omniauth-oauth
PORTVERSION=	1.2.1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Generic OAuth strategy for OmniAuth
WWW=		https://github.com/omniauth/omniauth-oauth

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-oauth>=0:net/rubygem-oauth \
		rubygem-omniauth1>=1.0<3:security/rubygem-omniauth1 \
		rubygem-rack>=1.6.2,3<4,3:www/rubygem-rack

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
