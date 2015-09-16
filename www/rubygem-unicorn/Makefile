# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unicorn
PORTVERSION=	4.9.0
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Unicorn is an HTTP server for Rack applications

LICENSE=	GPLv2 GPLv3 RUBY
LICENSE_COMB=	dual

RUN_DEPENDS=	rubygem-kgio>=2.6:${PORTSDIR}/devel/rubygem-kgio \
		rubygem-rack16>=0:${PORTSDIR}/www/rubygem-rack16 \
		rubygem-raindrops>=0.7:${PORTSDIR}/www/rubygem-raindrops

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/unicorn bin/unicorn_rails

.include <bsd.port.mk>
