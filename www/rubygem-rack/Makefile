# $FreeBSD$

# XXX: If updating this port, please check compatibality with at least the following ports,
# XXX: preferably, the full rubygem-* tree.  rack version requirements are specified with ~>
# XXX: which requires *EXACTLY* that version.
#
# 	www/rubygem-actionpack

PORTNAME=	rack
PORTVERSION=	1.4.7
PORTEPOCH=	3
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Rack, a Ruby Webserver Interface

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem shebangfix

SHEBANG_FILES=	test/cgi/test.ru
SHEBANG_LANG=	rackup
rackup_OLD_CMD=	../../bin/rackup
rackup_CMD=	${PREFIX}/bin/rackup

PORTSCOUT=	limit:^1\.4

PLIST_FILES=	bin/rackup

.include <bsd.port.mk>
