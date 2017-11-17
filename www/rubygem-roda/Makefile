# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	roda
PORTVERSION=	3.2.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Routing tree web toolkit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-rack>=2.0:www/rubygem-rack
TEST_DEPENDS=	rubygem-erubi>=0:www/rubygem-erubi \
		rubygem-haml>=0:www/rubygem-haml \
		rubygem-minitest>=5.7.0:devel/rubygem-minitest \
		rubygem-tilt>=2.0:devel/rubygem-tilt

USES=		gem
USE_RUBY=	yes
NO_ARCH=	yes

.include <bsd.port.mk>
