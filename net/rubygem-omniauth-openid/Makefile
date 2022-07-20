PORTNAME=	omniauth-openid
PORTVERSION=	2.0.1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	OpenID strategy for OmniAuth

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-omniauth>=1.0<3.0:security/rubygem-omniauth \
		rubygem-rack-openid>=1.4.0<1.5:www/rubygem-rack-openid

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
