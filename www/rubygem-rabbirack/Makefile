# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rabbirack
PORTVERSION=	2.0.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	tota@FreeBSD.org
COMMENT=	RabbiRack is a tool that controls Rabbit by Web browser

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	rubygem-haml>0:www/rubygem-haml \
		rubygem-locale>=2.0.6:devel/rubygem-locale \
		rubygem-rabbit>=2.0.0:misc/rubygem-rabbit \
		rubygem-sinatra>0:www/rubygem-sinatra

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem gettext
PLIST_FILES=	bin/rabbirack

.include <bsd.port.mk>
