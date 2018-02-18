# $FreeBSD$

PORTNAME=	compass-rails
PORTVERSION=	3.0.2
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Integrate Compass into Rails 2.3 and up

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		conflicting run depends
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2018-03-19

RUN_DEPENDS=	rubygem-compass>=1.0.0:textproc/rubygem-compass \
		rubygem-sass-rails-rails4>=0:textproc/rubygem-sass-rails-rails4 \
		rubygem-sprockets3>=0:devel/rubygem-sprockets3

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
