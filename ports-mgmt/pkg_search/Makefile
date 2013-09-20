# Created by: Matthias Schmidt
# $FreeBSD$

PORTNAME=	pkg_search
PORTVERSION=	1.3
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://www.mathematik.uni-marburg.de/~schmidtm/pkg_search/ \
		LOCAL/chinsan

MAINTAINER=	schmidtm@mathematik.uni-marburg.de
COMMENT=	A nifty script searching the ports database

PLIST_FILES=	bin/pkg_search

MAN1=		pkg_search.1

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1

.include <bsd.port.mk>
