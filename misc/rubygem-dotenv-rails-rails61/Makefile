PORTNAME=	dotenv-rails
DISTVERSION=	3.1.0
CATEGORIES=	misc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails61

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Autoload dotenv in Rails
WWW=		https://github.com/bkeepers/dotenv

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-dotenv>=${PORTVERSION}:misc/rubygem-dotenv \
		rubygem-railties61>=6.1:www/rubygem-railties61

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
