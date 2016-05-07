# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	omniauth-openid
PORTVERSION=	1.0.1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	OpenID strategy for OmniAuth

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-omniauth>=1.0:security/rubygem-omniauth \
		rubygem-rack-openid>=1.3.1:www/rubygem-rack-openid

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
