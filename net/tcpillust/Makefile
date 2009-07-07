# New ports collection makefile for:	tcpillust
# Date created:		14 April 2000
# Whom:			nishida@sfc.wide.ad.jp
#
# $FreeBSD$
#

PORTNAME=	tcpillust
PORTVERSION=	2.01
PORTEPOCH=	1
CATEGORIES=	net tcl tk
MASTER_SITES=	http://www.jp.nishida.org/tcpillust/

MAINTAINER=	nishida@sfc.wide.ad.jp
COMMENT=	A graphical TCP connection analysis tool

USE_TCL=	yes
USE_TK=		yes
USE_XORG=	xt
USE_MOTIF=	yes

MAN1=		tcpillust.1
PORTDOCS=	tcpclient.log tcpserver.log
PLIST_DIRS=	share/tcpillust
PLIST_FILES=	bin/tcpillust \
		share/tcpillust/tcpillust.tcl \
		share/tcpillust/back.xbm \
		share/tcpillust/forward.xbm \
		share/tcpillust/zoomin.xbm \
		share/tcpillust/zoomout.xbm

WRKSRC=		${WRKDIR}/${PORTNAME}

do-build:
.for file in binread.c button.c draw.c parser.c tcpillust.c tcpdump/print-tcp.c
	${CC} ${CFLAGS} -I${LOCALBASE}/include/ -I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR} \
	-I${LOCALBASE}/include -DILTDIR=\"${DATADIR}\" -c ${WRKSRC}/${file} -o ${WRKSRC}/${file:S/.c/.o/}
.endfor
	${CC} ${CFLAGS} -L${TCL_LIBDIR} -L${TK_LIBDIR} -L${LOCALBASE}/lib \
	-lm -ltcl${TCL_VER:S/.//} -ltk${TK_VER:S/.//} ${WRKSRC}/*.o ${WRKSRC}/tcpdump/*.o -o ${WRKSRC}/tcpillust -lpcap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpillust ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/tcpillust.tcl ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/*.xbm ${DATADIR}/
	${INSTALL_MAN} ${WRKSRC}/tcpillust.man ${PREFIX}/man/man1/tcpillust.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
