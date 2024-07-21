PORTNAME=	turbo-rails
PORTVERSION=	2.0.6
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails70

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Speed of a single-page web application without having to write any JavaScript
WWW=		https://github.com/hotwired/turbo-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack70>=6.0.0:www/rubygem-actionpack70 \
		rubygem-activejob70>=6.0.0:devel/rubygem-activejob70 \
		rubygem-railties70>=6.0.0:www/rubygem-railties70

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
