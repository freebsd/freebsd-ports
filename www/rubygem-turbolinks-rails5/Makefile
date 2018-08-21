# $FreeBSD$

PORTNAME=	turbolinks
PORTVERSION=	5.2.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails5

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Turbolinks makes following links in your web application faster

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-coffee-rails-rails5>=4.0.1:devel/rubygem-coffee-rails-rails5 \
		rubygem-turbolinks-source>=5.2:www/rubygem-turbolinks-source

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
