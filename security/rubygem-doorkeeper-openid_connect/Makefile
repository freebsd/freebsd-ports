PORTNAME=	doorkeeper-openid_connect
PORTVERSION=	1.8.11
PORTREVISION=	1
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	OpenID Connect extension for Doorkeeper
WWW=		https://github.com/doorkeeper-gem/doorkeeper-openid_connect

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-doorkeeper-rails-gitlab>=5.5<5.9:security/rubygem-doorkeeper-rails-gitlab \
		rubygem-jwt>=2.5:www/rubygem-jwt \
		rubygem-ostruct>=0.5:devel/rubygem-ostruct

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
