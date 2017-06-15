# $FreeBSD$

PORTNAME=	create-rb-port
PORTVERSION=	0.0.1
CATEGORIES=	ports-mgmt

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Script to ease creation of rubygem- ports

RUN_DEPENDS=	gem:devel/ruby-gems

USE_GITHUB=	yes
GH_ACCOUNT=	swills
GH_PROJECT=	freebsd-ruby

NO_BUILD=	yes

PLIST_FILES=	bin/create-rb-port

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/create-rb-port ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
