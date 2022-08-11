PORTNAME=	tclsyslog
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	sysutils tcl
MASTER_SITES=	http://ftp.wagner.pp.ru/pub/tcl/tclsyslog/

MAINTAINER=	frank@fenor.de
COMMENT=	Tcl Interface to Syslog

USES=		tcl

WRKSRC=		${WRKDIR}/tclsyslog

PLIST_FILES=	lib/syslog/libsyslog.so.2.1 \
		lib/syslog/pkgIndex.tcl \
		man/mann/syslog.n.gz

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|CC=gcc|CC=${CC}|' \
		-e 's|	gcc|	$${CC} $${CFLAGS}|' \
		-e 's|CFLAGS=|CFLAGS=${CFLAGS} |' \
		-e 's|LDFLAGS=-shared -L/usr/local/lib|LDFLAGS=-shared -L${PREFIX}/lib|' \
		-e 's|PREFIX=/usr/local|PREFIX=${STAGEDIR}${PREFIX}|' \
		-e 's|INCLUDES=-I/usr/local/include|INCLUDES=-I${TCL_INCLUDEDIR}|' \
		-e 's|LOADLIBES=-ltclstub8.2|LOADLIBES=-ltclstub${TCL_SHLIB_VER}|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
