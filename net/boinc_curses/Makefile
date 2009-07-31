# New ports collection makefile for:	boinc_curses
# Date created:				15 Feb 2007
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	boinc_curses
PORTVERSION=	0.1.9
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.oook.cz/bsd/boinc_curses/

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Console, ncurses based monitor and manager for BOINC

BUILD_DEPENDS=	${LOCALBASE}/lib/libboinc.a:${PORTSDIR}/net/boinc-client

USE_BZIP2=	yes
MAKE_ENV=	BOINCLIBDIR=${LOCALBASE}/lib BOINCINCDIR=${LOCALBASE}/include/boinc

PLIST_FILES=	bin/boinc_curses

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
