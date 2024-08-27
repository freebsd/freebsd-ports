PORTNAME=	omniauth_openid_connect
PORTVERSION=	0.8.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	OpenID Connect Strategy for OmniAuth
WWW=		https://github.com/m0n9oose/omniauth_openid_connect

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-omniauth>=1.9<3:security/rubygem-omniauth \
		rubygem-openid_connect>=2.2<3:net/rubygem-openid_connect

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
