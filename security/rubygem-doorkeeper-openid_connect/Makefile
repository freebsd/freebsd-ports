PORTNAME=	doorkeeper-openid_connect
PORTVERSION=	1.8.7
PORTREVISION=	2
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	OpenID Connect extension for Doorkeeper
WWW=		https://github.com/doorkeeper-gem/doorkeeper-openid_connect

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-doorkeeper-rails70>=5.5<5.8:security/rubygem-doorkeeper-rails70 \
		rubygem-jwt>=2.5:www/rubygem-jwt

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
