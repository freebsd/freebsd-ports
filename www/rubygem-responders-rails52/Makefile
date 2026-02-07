PORTNAME=	responders
PORTVERSION=	3.1.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails52

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple Ruby DSL for making HTTP requests
WWW=		https://github.com/heartcombo/responders

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack52>=5.2:www/rubygem-actionpack52 \
		rubygem-railties52>=5.2:www/rubygem-railties52

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^3\.1\.

.include <bsd.port.mk>
