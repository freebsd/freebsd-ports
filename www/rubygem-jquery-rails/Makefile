# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jquery-rails
PORTVERSION=	3.1.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Provides a Rails generator for jQuery

LICENSE=	MIT

RUN_DEPENDS=	rubygem-railties>=3.0:${PORTSDIR}/www/rubygem-railties \
		rubygem-thor>=0.14:${PORTSDIR}/devel/rubygem-thor

PORTSCOUT=	limit:^3.*

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
