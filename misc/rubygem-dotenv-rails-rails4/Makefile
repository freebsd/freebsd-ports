PORTNAME=	dotenv-rails
PORTVERSION=	2.8.1
CATEGORIES=	misc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails4

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Autoload dotenv in Rails
WWW=		https://github.com/bkeepers/dotenv

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-dotenv>=${PORTVERSION}:misc/rubygem-dotenv \
		rubygem-railties4>=3.2:www/rubygem-railties4

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
