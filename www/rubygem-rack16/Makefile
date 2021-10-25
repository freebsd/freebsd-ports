# XXX: If updating this port, please check compatibality with at least the following ports,
# XXX: preferably, the full rubygem-* tree.  rack version requirements are specified with ~>
# XXX: which requires *EXACTLY* that version.
#
# 	www/rubygem-actionpack4

PORTNAME=	rack
PORTVERSION=	1.6.13
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	16

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rack, a Ruby Webserver Interface

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

CPE_VENDOR=	rack_project

PORTSCOUT=	limit:^1\.6\.

SHEBANG_FILES=	test/cgi/test.ru
SHEBANG_LANG=	rackup
rackup_OLD_CMD=	../../bin/rackup
rackup_CMD=	${LOCALBASE}/bin/rackup

# Avoid CONFLICTS_INSTALL with www/rubygem-rack
post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/rackup

.include <bsd.port.mk>
