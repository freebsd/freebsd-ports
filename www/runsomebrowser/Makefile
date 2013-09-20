# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	runsomebrowser
PORTVERSION=	0.2
CATEGORIES=	www
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/ \
		http://jbacon.dyndns.org/~bacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Script for running the an available WEB browser

NO_BUILD=	yes

MAN1=		runsomebrowser.1

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/runsomebrowser ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/runsomebrowser.1 ${MAN1PREFIX}/man/man1

PLIST_FILES=	bin/runsomebrowser

.include <bsd.port.mk>
