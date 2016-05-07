# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	boinc_curses
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	LOCAL/rene http://www.oook.cz/bsd/boinc_curses/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console, ncurses based monitor and manager for BOINC

BUILD_DEPENDS=	${LOCALBASE}/lib/libboinc.a:net/boinc-client

USES=		ncurses tar:bzip2
MAKE_ENV=	BOINCLIBDIR=${LOCALBASE}/lib BOINCINCDIR=${LOCALBASE}/include/boinc

PLIST_FILES=	bin/boinc_curses

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
