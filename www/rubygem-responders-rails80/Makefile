PORTNAME=	responders
PORTVERSION=	3.2.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails80

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple Ruby DSL for making HTTP requests
WWW=		https://github.com/heartcombo/responders

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack80>=7.0:www/rubygem-actionpack80 \
		rubygem-railties80>=7.0:www/rubygem-railties80

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
