# Created by: Michael Moll <kvedulv@kvedulv.de>
# $FreeBSD$

PORTNAME=	hammer_cli
PORTVERSION=	0.0.18
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Provides CLI interfaces for Ruby apps

LICENSE=	GPLv3

RUN_DEPENDS=	rubygem-awesome_print>=1.1.0:${PORTSDIR}/devel/rubygem-awesome_print \
		rubygem-clamp>=0.6.3:${PORTSDIR}/devel/rubygem-clamp \
		rubygem-fastercsv>=1.5.5:${PORTSDIR}/devel/rubygem-fastercsv \
		rubygem-highline>=1.6.20:${PORTSDIR}/devel/rubygem-highline \
		rubygem-logging>=1.8.1:${PORTSDIR}/devel/rubygem-logging \
		rubygem-mime-types>=1.0:${PORTSDIR}/misc/rubygem-mime-types \
		rubygem-rest-client>=1.6.7:${PORTSDIR}/www/rubygem-rest-client \
		rubygem-table_print>=1.5.1:${PORTSDIR}/devel/rubygem-table_print

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/hammer

.include <bsd.port.mk>
