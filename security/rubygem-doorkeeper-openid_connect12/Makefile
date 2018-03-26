# $FreeBSD$

PORTNAME=	doorkeeper-openid_connect
PORTVERSION=	1.2.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	12

MAINTAINER=	idefix@fechner.net
COMMENT=	OpenID Connect extension for Doorkeeper

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-doorkeeper>=4.3:security/rubygem-doorkeeper \
		rubygem-json-jwt>=1.6:www/rubygem-json-jwt

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
