# Created by: nishida@sfc.wide.ad.jp
# $FreeBSD$

PORTNAME=	tcpillust
PORTVERSION=	2.01
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net tcl tk
MASTER_SITES=	https://cschubert.com/distfiles/ \
		LOCAL/cy

MAINTAINER=	nishida@sfc.wide.ad.jp
COMMENT=	Graphical TCP connection analysis tool

USES=		motif tk xorg
USE_XORG=	xt

PORTDOCS=	tcpclient.log tcpserver.log
PLIST_FILES=	bin/tcpillust \
		man/man1/tcpillust.1.gz \
		share/tcpillust/tcpillust.tcl \
		share/tcpillust/back.xbm \
		share/tcpillust/forward.xbm \
		share/tcpillust/zoomin.xbm \
		share/tcpillust/zoomout.xbm

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-build:
.for file in binread.c button.c draw.c parser.c tcpillust.c tcpdump/print-tcp.c
	${CC} ${CFLAGS} -DHAVE_BPF_DUMP -I/usr/include -I/usr/include/pcap -I${LOCALBASE}/include/ -I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR} \
	-I${LOCALBASE}/include -DILTDIR=\"${DATADIR}\" -c ${WRKSRC}/${file} -o ${WRKSRC}/${file:S/.c/.o/}
.endfor
	${CC} ${CFLAGS} -L/lib -L/usr/lib -L${TCL_LIBDIR} -L${TK_LIBDIR} -L${LOCALBASE}/lib \
	-lm -ltcl${TCL_VER:S/.//} -ltk${TK_VER:S/.//} ${WRKSRC}/*.o ${WRKSRC}/tcpdump/*.o -o ${WRKSRC}/tcpillust -lpcap -lX11

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpillust ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/tcpillust.tcl ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/*.xbm ${STAGEDIR}${DATADIR}/
	${INSTALL_MAN} ${WRKSRC}/tcpillust.man ${STAGEDIR}${PREFIX}/man/man1/tcpillust.1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
