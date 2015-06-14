# Created by: Johannes Jost Meixner <xmj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sass-rails
PORTVERSION=	5.0.3
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	5

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Sass adapter for the Rails asset pipeline

LICENSE=	MIT

RUN_DEPENDS=	rubygem-railties4>=4.0.0:${PORTSDIR}/www/rubygem-railties4 \
		rubygem-sass32>=3.2.0:${PORTSDIR}/textproc/rubygem-sass32 \
		rubygem-sprockets3>=3.0.3:${PORTSDIR}/devel/rubygem-sprockets \
		rubygem-sprockets-rails>=2.0:${PORTSDIR}/devel/rubygem-sprockets-rails \
		rubygem-tilt1>=1.1:${PORTSDIR}/devel/rubygem-tilt1

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
