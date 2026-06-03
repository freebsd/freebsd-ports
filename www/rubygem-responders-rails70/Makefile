PORTNAME=	responders
PORTVERSION=	3.2.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails70

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple Ruby DSL for making HTTP requests
WWW=		https://github.com/heartcombo/responders

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack70>=7.0:www/rubygem-actionpack70 \
		rubygem-railties70>=7.0:www/rubygem-railties70

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
