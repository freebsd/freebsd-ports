# Created by: Jason Helfman <jhelfman@experts-exchange.com>
# $FreeBSD$

PORTNAME=	compass
PORTVERSION=	0.12.4
CATEGORIES=	textproc ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Provides an open-source CSS authoring framework

LICENSE=	MIT

RUN_DEPENDS=	rubygem-chunky_png>=1.2:${PORTSDIR}/graphics/rubygem-chunky_png \
		rubygem-fssm>=0.2.7:${PORTSDIR}/sysutils/rubygem-fssm \
		rubygem-sass32>=3.1:${PORTSDIR}/textproc/rubygem-sass32

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/compass

.include <bsd.port.mk>
