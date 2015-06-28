# $FreeBSD$

PORTNAME=	compass-rails
PORTVERSION=	2.0.4
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Integrate Compass into Rails 2.3 and up

LICENSE=	MIT

RUN_DEPENDS=	rubygem-compass>=1.0.0:${PORTSDIR}/textproc/rubygem-compass \
		rubygem-sass-rails>=0:${PORTSDIR}/textproc/rubygem-sass-rails \
		rubygem-sprockets>=0:${PORTSDIR}/devel/rubygem-sprockets

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
