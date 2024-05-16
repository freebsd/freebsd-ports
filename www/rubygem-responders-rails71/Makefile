PORTNAME=	responders
PORTVERSION=	3.1.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails71

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple Ruby DSL for making HTTP requests
WWW=		https://github.com/heartcombo/responders

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack71>=5.2:www/rubygem-actionpack71 \
		rubygem-railties71>=5.2:www/rubygem-railties71

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
