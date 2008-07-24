# New ports collection makefile for:	tclsyslog
# Date created:				31 March 2008
# Whom:					Frank Fenor <frank@fenor.de>
#
# $FreeBSD$
#

PORTNAME=	tclsyslog
PORTVERSION=	2.1
CATEGORIES=	sysutils tcl
MASTER_SITES=	http://ftp.wagner.pp.ru/pub/tcl/tclsyslog/

MAINTAINER=	frank@fenor.de
COMMENT=	Tcl Interface to Syslog

USE_TCL=	82+
MANN=		syslog.n
MANCOMPRESSED=	no

WRKSRC=		${WRKDIR}/tclsyslog

PLIST_FILES=	lib/syslog/libsyslog.so.2.1 \
		lib/syslog/pkgIndex.tcl
PLIST_DIRS=	lib/syslog

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|CC=gcc|CC=${CC}|' \
		-e 's|	gcc|	$${CC} $${CFLAGS}|' \
		-e 's|CFLAGS=|CFLAGS=${CFLAGS} |' \
		-e 's|LDFLAGS=-shared -L/usr/local/lib|LDFLAGS=-shared -L${PREFIX}/lib|' \
		-e 's|PREFIX=/usr/local|PREFIX=${PREFIX}|' \
		-e 's|INCLUDES=-I/usr/local/include|INCLUDES=-I${TCL_INCLUDEDIR}|' \
		-e 's|LOADLIBES=-ltclstub8.2|LOADLIBES=-ltclstub${TCL_VER:S/.//}|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
