# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jquery-rails
PORTVERSION=	3.1.4
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Provides a Rails generator for jQuery

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-railties>=3.0:www/rubygem-railties \
		rubygem-thor>=0.14:devel/rubygem-thor

PORTSCOUT=	limit:^3.*

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

DEPRECATED=	Depends on deprecated www/rubygem-railties
EXPIRATION_DATE=	2017-01-07

.include <bsd.port.mk>
