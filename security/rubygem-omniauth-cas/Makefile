PORTNAME=	omniauth-cas
PORTVERSION=	3.0.2
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Central Authentication Service (CAS) strategy for OmniAuth
WWW=		https://github.com/dlindahl/omniauth-cas

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=2.8<3:www/rubygem-addressable \
		rubygem-nokogiri>=1.12<2:textproc/rubygem-nokogiri \
		rubygem-omniauth>=2.1<3:security/rubygem-omniauth

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
