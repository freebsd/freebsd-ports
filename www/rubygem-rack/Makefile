# $FreeBSD$

PORTNAME=	rack
PORTVERSION=	2.0.3
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

PLIST_FILES=	bin/rackup

SHEBANG_FILES=	test/cgi/test.ru
SHEBANG_LANG=	rackup
rackup_OLD_CMD=	../../bin/rackup
rackup_CMD=	${PREFIX}/bin/rackup

.include <bsd.port.mk>
