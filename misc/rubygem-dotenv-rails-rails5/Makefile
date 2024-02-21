PORTNAME=	dotenv-rails
PORTVERSION=	2.8.1
PORTREVISION=	1
CATEGORIES=	misc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails5

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Autoload dotenv in Rails
WWW=		https://github.com/bkeepers/dotenv

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-dotenv2>=${PORTVERSION}:misc/rubygem-dotenv2 \
		rubygem-railties5>=3.2:www/rubygem-railties5

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
