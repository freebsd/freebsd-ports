# Created by: Chung-Kie Tung <tung@turtle.ee.ncku.edu.tw>
# $FreeBSD$

PORTNAME=	tcpview
PORTVERSION=	1.0
PORTREVISION=	6
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.cac.washington.edu/pub/noc-tools/tcpview/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Motif-based TCP/IP protocol analyzer

USES=		bison motif

MAN1=		tcpview.1

NO_STAGE=	yes
post-patch:
.for f in nametoaddr.c addrtoname.c print-nfs.c detail-tcp.c tv_addrtoname.c
	@${REINPLACE_CMD} -e 's/NTOHL/ntohl/ ; s/NTOHS/ntohs/' ${WRKSRC}/${f}
.endfor

post-install:
	${INSTALL_DATA} ${WRKSRC}/DOC/Tcpview ${LOCALBASE}/lib/X11/app-defaults

.include <bsd.port.mk>
