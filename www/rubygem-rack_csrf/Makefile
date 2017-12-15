# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rack_csrf
PORTVERSION=	2.6.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Anti-CSRF Rack middleware

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.rdoc

RUN_DEPENDS=	rubygem-rack>=1.1.0:www/rubygem-rack
TEST_DEPENDS=	rubygem-rspec>0:devel/rubygem-rspec

USES=		gem
USE_RUBY=	yes
NO_ARCH=	yes

.include <bsd.port.mk>
