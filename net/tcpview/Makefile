# New ports collection makefile for:   tcpview-1.0
# Date created:        18 Aug 2000
# Whom:                Chung-Kie Tung <tung@turtle.ee.ncku.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	tcpview
PORTVERSION=	1.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.cac.washington.edu/pub/noc-tools/tcpview/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org

USE_BISON=	yes
USE_MOTIF=	yes
USE_REINPLACE=	yes

#MAKE_ARGS=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
#		INSTALL_MAN="${INSTALL_MAN}" \
#		INSTALL_DATA="${INSTALL_DATA}" \
#		PREFIX="${PREFIX}" \
#		X11BASE="${X11BASE}"

MAN1=		tcpview.1

post-patch:
.for f in nametoaddr.c addrtoname.c print-nfs.c detail-tcp.c tv_addrtoname.c
	@${REINPLACE_CMD} -e 's/NTOHL/ntohl/ ; s/NTOHS/ntohs/' ${WRKSRC}/${f}
.endfor
	
post-install:
	${CP} ${WRKSRC}/DOC/Tcpview ${X11BASE}/lib/X11/app-defaults/

.include <bsd.port.mk>
