# New ports collection makefile for:	knews
# Version required:     0.9.6
# Date created:         Sun Apr 14 09:23:59 MET DST 1996
# Whom:                 Andreas Klemm <andreas@knobel.gun.de>
#
# $Id$
#

DISTNAME=	knews-0.9.6
CATEGORIES+=	x11 news
MASTER_SITES=	ftp://ftp.nada.kth.se/home/su95-kjo/knews/ \
	ftp://sunsite.unc.edu/pub/Linux/X11/xapps/networked/ \
	ftp://ftp.cc.gatech.edu/ac88/linux/X11/xapps/networked/ \
	ftp://ftp.germany.eu.net/pub/os/Linux/Mirror.SunSITE/X11/xapps/networked/ \
	ftp://ftp.funet.fi/pub/mirrors/sunsite.unc.edu/pub/Linux/X11/xapps/networked/

MAINTAINER=	andreas@knobel.gun.de

LIB_DEPENDS=    Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/knews
USE_IMAKE=	yes
MAKE_FLAGS=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/man/man1 \
		XAPPLOADDIR=${PREFIX}/lib/X11/app-defaults  -f

.include <bsd.port.mk>
