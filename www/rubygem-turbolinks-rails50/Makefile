# $FreeBSD$

PORTNAME=	turbolinks
PORTVERSION=	5.0.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails50

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Turbolinks makes following links in your web application faster

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-coffee-rails-rails50>=4.0.1:devel/rubygem-coffee-rails-rails50 \
		rubygem-turbolinks-source>=5:www/rubygem-turbolinks-source

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
