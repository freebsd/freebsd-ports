PORTNAME=	responders
PORTVERSION=	3.1.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails61

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple Ruby DSL for making HTTP requests
WWW=		https://github.com/heartcombo/responders

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack61>=5.2:www/rubygem-actionpack61 \
		rubygem-railties61>=5.2:www/rubygem-railties61

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^3\.1\.

.include <bsd.port.mk>
