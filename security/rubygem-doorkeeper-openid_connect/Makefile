PORTNAME=	doorkeeper-openid_connect
PORTVERSION=	1.7.5
PORTREVISION=	2
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	OpenID Connect extension for Doorkeeper
WWW=		https://github.com/doorkeeper-gem/doorkeeper-openid_connect

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-doorkeeper>=5.2<5.6:security/rubygem-doorkeeper \
		rubygem-json-jwt115>=1.11:www/rubygem-json-jwt115

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
