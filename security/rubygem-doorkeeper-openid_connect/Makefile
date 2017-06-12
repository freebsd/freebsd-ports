# $FreeBSD$

PORTNAME=	doorkeeper-openid_connect
PORTVERSION=	1.1.2
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	OpenID Connect extension for Doorkeeper

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-doorkeeper>=4.0:security/rubygem-doorkeeper \
		rubygem-json-jwt>=1.6:www/rubygem-json-jwt

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
