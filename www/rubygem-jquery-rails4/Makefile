# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jquery-rails
PORTVERSION=	4.0.4
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	4

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Provides a Rails generator for jQuery

LICENSE=	MIT

RUN_DEPENDS=	rubygem-rails-dom-testing>=1.0:${PORTSDIR}/textproc/rubygem-rails-dom-testing \
		rubygem-railties4>=4.2.0:${PORTSDIR}/www/rubygem-railties4 \
		rubygem-thor>=0.14:${PORTSDIR}/devel/rubygem-thor

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
