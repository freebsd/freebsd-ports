# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	thin
PORTVERSION=	1.6.3
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Fast and simple Ruby web server

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual

RUN_DEPENDS=	rubygem-daemons>=1.0.9:${PORTSDIR}/devel/rubygem-daemons \
		rubygem-eventmachine>=1.0:${PORTSDIR}/devel/rubygem-eventmachine \
		rubygem-rack16>=1.0:${PORTSDIR}/www/rubygem-rack16

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/thin

.include <bsd.port.mk>
