# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jquery-rails
PORTVERSION=	4.3.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails50

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Provides a Rails generator for jQuery

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-rails-dom-testing-rails50>=1.0:textproc/rubygem-rails-dom-testing-rails50 \
		rubygem-railties50>=4.2.0:www/rubygem-railties50 \
		rubygem-thor>=0.14:devel/rubygem-thor

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
