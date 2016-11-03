# Created by: Matthias Schmidt
# $FreeBSD$

PORTNAME=	pkg_search
PORTVERSION=	1.3
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://www.mathematik.uni-marburg.de/~schmidtm/pkg_search/ \
		LOCAL/chinsan

MAINTAINER=	schmidtm@mathematik.uni-marburg.de
COMMENT=	Nifty script searching the ports database

IGNORE_DragonFly=	Requires update to work for DragonFly

PLIST_FILES=	bin/pkg_search man/man1/pkg_search.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
