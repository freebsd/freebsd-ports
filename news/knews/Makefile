# New ports collection makefile for:	knews
# Version required:     0.9.8
# Date created:         Sun Apr 14 09:23:59 MET DST 1996
# Whom:                 Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.8 1996/11/18 10:36:41 asami Exp $
#

DISTNAME=	knews-0.9.8
CATEGORIES=	x11 news
MASTER_SITES=	ftp://ftp.nada.kth.se/home/su95-kjo/knews/

MAINTAINER=	andreas@FreeBSD.ORG

LIB_DEPENDS=    Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/knews
USE_IMAKE=	yes
MAKE_FLAGS=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/man/man1 \
		XAPPLOADDIR=${PREFIX}/lib/X11/app-defaults  -f

.include <bsd.port.mk>
