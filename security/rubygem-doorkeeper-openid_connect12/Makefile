# $FreeBSD$

PORTNAME=	doorkeeper-openid_connect
PORTVERSION=	1.2.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	12

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	OpenID Connect extension for Doorkeeper

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Obsoleted by update of www/gitlab. Please use security/rubygem-doorkeeper-openid_connect instead.
EXPIRATION_DATE=	2018-06-30

CONFLICTS_INSTALL=	rubygem-doorkeeper-openid_connect

RUN_DEPENDS=	rubygem-doorkeeper42>=4.0:security/rubygem-doorkeeper42 \
		rubygem-json-jwt>=1.6:www/rubygem-json-jwt

PORTSCOUT=	limit:^1\.2\.

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
