# $FreeBSD$

PORTNAME=	compass-rails
PORTVERSION=	3.0.2
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Integrate Compass into Rails 2.3 and up

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		conflicting run depends

RUN_DEPENDS=	rubygem-compass>=1.0.0:textproc/rubygem-compass \
		rubygem-sass-rails5>=0:textproc/rubygem-sass-rails5 \
		rubygem-sprockets3>=0:devel/rubygem-sprockets3

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
