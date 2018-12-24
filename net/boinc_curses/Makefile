# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	boinc_curses
PORTVERSION=	0.2.3
CATEGORIES=	net
MASTER_SITES=	http://www.oook.cz/bsd/boinc_curses/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console, ncurses based monitor and manager for BOINC

LICENSE=	LGPL21+

BUILD_DEPENDS=	${LOCALBASE}/lib/libboinc.a:net/boinc-client

USES=		compiler:c++11-lang ncurses tar:bzip2
MAKE_ENV=	BOINCLIBDIR=${LOCALBASE}/lib BOINCINCDIR=${LOCALBASE}/include/boinc

PLIST_FILES=	bin/boinc_curses

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
