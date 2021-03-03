# $FreeBSD$

PORTNAME=	doorkeeper-openid_connect
PORTVERSION=	1.7.5
PORTREVISION=	1
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	OpenID Connect extension for Doorkeeper

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-doorkeeper>=5.2<5.6:security/rubygem-doorkeeper \
		rubygem-json-jwt>=1.11:www/rubygem-json-jwt

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
