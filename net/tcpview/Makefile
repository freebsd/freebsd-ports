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

MAINTAINER=	tung@turtle.ee.ncku.edu.tw

USE_BISON=	yes
USE_MOTIF=	yes

MAN1=		tcpview.1

post-install:
	strip ${PREFIX}/bin/tcpview
	${CP} ${WRKSRC}/DOC/Tcpview ${X11BASE}/lib/X11/app-defaults/

.include <bsd.port.mk>
