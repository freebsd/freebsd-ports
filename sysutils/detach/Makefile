# Created by: arnej@pvv.org
# $FreeBSD$

PORTNAME=	detach
PORTVERSION=	1.3
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.ntnu.no/pub/unix/utils/

MAINTAINER=	arnej@pvv.org
COMMENT=	Start a process detached from a terminal

BROKEN=		unfetchable

PLIST_FILES=	bin/detach man/man1/detach.1.gz

do-install:
	${INSTALL_PROGRAM} -m 0755 ${WRKSRC}/detach ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/detach.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
