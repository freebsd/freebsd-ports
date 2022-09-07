PORTNAME=	omniauth-cas
PORTVERSION=	2.0.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Central Authentication Service (CAS) strategy for OmniAuth
WWW=		https://github.com/dlindahl/omniauth-cas

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=2.3<3:www/rubygem-addressable \
		rubygem-nokogiri>=1.5<2:textproc/rubygem-nokogiri \
		rubygem-omniauth1>=1.2<2:security/rubygem-omniauth1

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
