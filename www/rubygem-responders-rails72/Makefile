PORTNAME=	responders
PORTVERSION=	3.2.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails72

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple Ruby DSL for making HTTP requests
WWW=		https://github.com/heartcombo/responders

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack72>=7.0:www/rubygem-actionpack72 \
		rubygem-railties72>=7.0:www/rubygem-railties72

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
