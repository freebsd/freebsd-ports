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

RUN_DEPENDS=	rubygem-haml>0:${PORTSDIR}/www/rubygem-haml \
		rubygem-locale>=2.0.6:${PORTSDIR}/devel/rubygem-locale \
		rubygem-rabbit>=2.0.0:${PORTSDIR}/misc/rubygem-rabbit \
		rubygem-sinatra>0:${PORTSDIR}/www/rubygem-sinatra

USE_GETTEXT=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/rabbirack

.include <bsd.port.mk>
