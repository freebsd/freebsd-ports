PORTNAME=	responders
PORTVERSION=	3.1.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails60

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple Ruby DSL for making HTTP requests
WWW=		https://github.com/heartcombo/responders

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack60>=5.2:www/rubygem-actionpack60 \
		rubygem-railties60>=5.2:www/rubygem-railties60

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^3\.1\.

.include <bsd.port.mk>
