# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	puma
PORTVERSION=	1.6.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Highly concurrent HTTP 1.1 server for Ruby/Rack applications

RUN_DEPENDS=	rubygem-rack>=1.4.5:${PORTSDIR}/www/rubygem-rack

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/pumactl \
				bin/puma

.include <bsd.port.mk>
