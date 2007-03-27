# New ports collection makefile for:	tcpillust
# Date created:		14 April 2000
# Whom:			nishida@csl.sony.co.jp
#
# $FreeBSD$
#

PORTNAME=	tcpillust
PORTVERSION=	1.0a
PORTREVISION=	1
CATEGORIES=	net tk84 tcl84
MASTER_SITES=	ftp://ftp.csl.sony.co.jp/CSL/nishida/

MAINTAINER=	nishida@csl.sony.co.jp
COMMENT=	A graphical TCP connection analysis tool

USE_TCL=	yes
USE_TK=		yes
USE_TK_BUILD=	yes
USE_XLIB=	yes
USE_MOTIF=	yes

MAN1=		tcpillust.1
PORTDOCS=	README FAQ tcpclient.log tcpserver.log
PLIST_DIRS=	share/tcpillust
PLIST_FILES=	bin/tcpillust \
		share/tcpillust/tcpillust.tcl \
		share/tcpillust/back.xbm \
		share/tcpillust/forward.xbm \
		share/tcpillust/zoomin.xbm \
		share/tcpillust/zoomout.xbm

do-build:
.for file in binread.c button.c draw.c parser.c tcpillust.c
	${CC} ${CFLAGS} -I${LOCALBASE}/include/ -I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR} \
	-I${X11BASE}/include -DILTDIR=\"${DATADIR}\" -c ${WRKSRC}/${file} -o ${WRKSRC}/${file:S/.c/.o/}
.endfor
	${CC} ${CFLAGS} -L${TCL_LIBDIR} -L${TK_LIBDIR} -L${LOCALBASE}/lib \
	-lm -lpcap -ltcl${TCL_VER:S/.//} -ltk${TK_VER:S/.//} ${WRKSRC}/*.o -o ${WRKSRC}/tcpillust

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpillust ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/tcpillust.tcl ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/*.xbm ${DATADIR}/
	${INSTALL_MAN} ${WRKSRC}/tcpillust.man ${PREFIX}/man/man1/tcpillust.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/FAQ ${WRKSRC}/sample/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
