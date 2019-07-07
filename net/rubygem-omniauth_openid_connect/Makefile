# Created by: Matthias Fechner <mfechner@FreeBSD.org>
# $FreeBSD$

PORTNAME=	omniauth_openid_connect
PORTVERSION=	0.3.1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	OpenID Connect Strategy for OmniAuth

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-addressable>=2.5:www/rubygem-addressable \
		rubygem-omniauth>=1.3:security/rubygem-omniauth \
		rubygem-openid_connect>=1.1:net/rubygem-openid_connect

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
