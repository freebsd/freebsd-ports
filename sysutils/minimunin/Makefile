# Created by: Dirk Engling <erdgeist@erdgeist.org>
# $FreeBSD$

PORTNAME=	minimunin
PORTVERSION=	0.3
CATEGORIES=	sysutils
MASTER_SITES=	http://erdgeist.org/arts/software/minimunin/

MAINTAINER=	erdgeist@erdgeist.org
COMMENT=	Tiny munin-node implementation written in pure bourne shell

USES=	tar:bzip2
PLIST_FILES=	bin/minimunin
SUB_FILES=	pkg-message

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/minimunin ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
