PORTNAME=	dotenv-rails
PORTVERSION=	2.8.1
PORTREVISION=	1
CATEGORIES=	misc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails50

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Autoload dotenv in Rails
WWW=		https://github.com/bkeepers/dotenv

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-dotenv2>=${PORTVERSION}<${PORTVERSION}_99:misc/rubygem-dotenv2 \
		rubygem-railties50>=3.2:www/rubygem-railties50

USES=		gem

NO_ARCH=	yes

# dotenv-rails 3.0.0+ requires Rails 6.1+
PORTSCOUT=	limit:^2\.

.include <bsd.port.mk>
