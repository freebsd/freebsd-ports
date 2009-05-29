# New ports collection makefile for:   tcpview
# Date created:        18 Aug 2000
# Whom:                Chung-Kie Tung <tung@turtle.ee.ncku.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	tcpview
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.cac.washington.edu/pub/noc-tools/tcpview/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Motif-based TCP/IP protocol analyzer

USE_BISON=	build
USE_MOTIF=	yes

MAN1=		tcpview.1

.include <bsd.port.pre.mk>
post-patch:
.for f in nametoaddr.c addrtoname.c print-nfs.c detail-tcp.c tv_addrtoname.c
	@${REINPLACE_CMD} -e 's/NTOHL/ntohl/ ; s/NTOHS/ntohs/' ${WRKSRC}/${f}
.endfor
.if	${OSVERSION} >= 800000
	@${REINPLACE_CMD} -e "s|-DCSLIP|-UCSLIP|" \
	    ${WRKSRC}/Makefile
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/DOC/Tcpview ${LOCALBASE}/lib/X11/app-defaults/

.include <bsd.port.post.mk>
