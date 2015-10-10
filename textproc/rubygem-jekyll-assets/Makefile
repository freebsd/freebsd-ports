# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jekyll-assets
PORTVERSION=	1.0.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Create javascript/CSS assets for Jekyll sites

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-fastimage>=1.6:${PORTSDIR}/graphics/rubygem-fastimage \
		rubygem-jekyll>=2:${PORTSDIR}/www/rubygem-jekyll \
		rubygem-mini_magick>=4.1:${PORTSDIR}/graphics/rubygem-mini_magick \
		rubygem-sass>=3.2:${PORTSDIR}/textproc/rubygem-sass \
		rubygem-sprockets>=2.10:${PORTSDIR}/devel/rubygem-sprockets \
		rubygem-sprockets-helpers>=0:${PORTSDIR}/devel/rubygem-sprockets-helpers \
		rubygem-sprockets-sass>=0:${PORTSDIR}/devel/rubygem-sprockets-sass

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
