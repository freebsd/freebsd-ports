# $FreeBSD$

PORTNAME=	rack
PORTVERSION=	2.0.8
PORTEPOCH=	3
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	20

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rack, a Ruby Webserver Interface

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^2\.0\.

SHEBANG_FILES=	test/cgi/test.ru
SHEBANG_LANG=	rackup
rackup_OLD_CMD=	../../bin/rackup
rackup_CMD=	${PREFIX}/bin/rackup

# Avoid CONFLICTS_INSTALL with www/rubygem-rack
post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/rackup

.include <bsd.port.mk>
