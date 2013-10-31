# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	thin
PORTVERSION=	1.2.11
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Fast and simple Ruby web server

RUN_DEPENDS=	rubygem-rack>=1.0.0:${PORTSDIR}/www/rubygem-rack \
		rubygem-eventmachine>=0.12.6:${PORTSDIR}/devel/rubygem-eventmachine \
		rubygem-daemons>=1.0.9:${PORTSDIR}/devel/rubygem-daemons

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/thin

.include <bsd.port.mk>
