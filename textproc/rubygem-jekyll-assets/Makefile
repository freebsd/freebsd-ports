# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jekyll-assets
PORTVERSION=	0.14.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Create javascript/CSS assets for Jekyll sites

RUN_DEPENDS=	rubygem-jekyll>=2.0:${PORTSDIR}/www/rubygem-jekyll \
		rubygem-fastimage>0:${PORTSDIR}/graphics/rubygem-fastimage \
		rubygem-mini_magick>=4.1:${PORTSDIR}/graphics/rubygem-mini_magick \
		rubygem-sass>=3.2:${PORTSDIR}/textproc/rubygem-sass \
		rubygem-sprockets>=2.10:${PORTSDIR}/devel/rubygem-sprockets \
		rubygem-sprockets-helpers>0:${PORTSDIR}/devel/rubygem-sprockets-helpers \
		rubygem-sprockets-sass>0:${PORTSDIR}/devel/rubygem-sprockets-sass

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
