PORTNAME=	omniauth-openid
PORTVERSION=	2.0.2
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	OpenID strategy for OmniAuth
WWW=		https://github.com/ruby-openid/omniauth-openid

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-omniauth>=1.1:security/rubygem-omniauth \
		rubygem-rack-openid>=1.4<2:www/rubygem-rack-openid \
		rubygem-ruby-openid>=2.1.8<3:net/rubygem-ruby-openid \
		rubygem-version_gem>=1.1.8<2:devel/rubygem-version_gem

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
