# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	responders
PORTVERSION=	1.1.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails3

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple Ruby DSL for making HTTP requests

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-railties>=3.2.0:www/rubygem-railties

PORTSCOUT=	limit:^1\.[0-9]*

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

DEPRECATED=	Depends on deprecated www/rubygem-railties
EXPIRATION_DATE=	2017-01-07

.include <bsd.port.mk>
