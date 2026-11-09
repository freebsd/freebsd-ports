PORTNAME=	omniauth
PORTVERSION=	2.3.1
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generalized Rack framework for multiple-provider authentication
WWW=		https://github.com/omniauth/omniauth

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-hashie>=3.5.2:devel/rubygem-hashie \
		rubygem-logger>=0:devel/rubygem-logger \
		rubygem-rack>=2.2.8,3:www/rubygem-rack \
		rubygem-rack-protection>=2.2.0:www/rubygem-rack-protection

USES=		cpe gem

NO_ARCH=	yes

.include <bsd.port.mk>
