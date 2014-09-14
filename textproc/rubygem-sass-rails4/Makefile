# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	sass-rails
PORTVERSION=	4.0.3
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Sass adapter for the Rails asset pipeline

LICENSE=	MIT

RUN_DEPENDS=	rubygem-railties4>=4.0.0:${PORTSDIR}/www/rubygem-railties4 \
		rubygem-sass32>=3.2.0:${PORTSDIR}/textproc/rubygem-sass32 \
		rubygem-sprockets211>=2.11:${PORTSDIR}/devel/rubygem-sprockets211 \
		rubygem-sprockets-rails>=2.0:${PORTSDIR}/devel/rubygem-sprockets-rails

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
