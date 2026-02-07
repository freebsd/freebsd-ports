PORTNAME=	dotenv-rails
PORTVERSION=	3.2.0
CATEGORIES=	misc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Autoload dotenv in Rails
WWW=		https://github.com/bkeepers/dotenv

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-dotenv>=${PORTVERSION}<${PORTVERSION}_99:misc/rubygem-dotenv \
		rubygem-railties71>=6.1:www/rubygem-railties71

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
