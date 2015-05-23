# $FreeBSD$

PORTNAME=	gitlab-grack
PORTVERSION=	2.0.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby/Rack Git Smart-HTTP Server Handler

LICENSE=	MIT

RUN_DEPENDS=	rubygem-rack15>=1.5.1:${PORTSDIR}/www/rubygem-rack15

CONFLICTS_INSTALL=	conserver-[0-9]* conserver-com-[0-9]*

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/console \
		bin/testserver

.include <bsd.port.mk>
