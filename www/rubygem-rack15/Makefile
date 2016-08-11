# $FreeBSD$

# XXX: If updating this port, please check compatibality with at least the following ports,
# XXX: preferably, the full rubygem-* tree.  rack version requirements are specified with ~>
# XXX: which requires *EXACTLY* that version.
#
# 	www/rubygem-innate

PORTNAME=	rack
PORTVERSION=	1.5.5
PORTEPOCH=	4
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	15

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
rackup_CMD=	${LOCALBASE}/bin/rackup

PORTSCOUT=	limit:^1\.5

# avoid duplicate file from www/rubygem-rack port
post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/rackup

.include <bsd.port.mk>
