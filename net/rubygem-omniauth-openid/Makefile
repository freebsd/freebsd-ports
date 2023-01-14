PORTNAME=	omniauth-openid
PORTVERSION=	2.0.1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	OpenID strategy for OmniAuth
WWW=		https://github.com/omniauth/omniauth-openid

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-omniauth>=1.0<3.0:security/rubygem-omniauth \
		rubygem-rack-openid>=1.4.0<1.5:www/rubygem-rack-openid

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
