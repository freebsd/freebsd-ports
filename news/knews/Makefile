# New ports collection makefile for:	knews
# Version required:     0.9.8
# Date created:         Sun Apr 14 09:23:59 MET DST 1996
# Whom:                 Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.22 1998/11/21 07:27:39 steve Exp $
#

DISTNAME=	knews-1.0b.1
CATEGORIES=	news
MASTER_SITES=	http://www.matematik.su.se/~kjj/

MAINTAINER=	andreas@FreeBSD.ORG

LIB_DEPENDS=    Xpm.4:${PORTSDIR}/graphics/xpm \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.2:${PORTSDIR}/graphics/png
RUN_DEPENDS=    newsp:${PORTSDIR}/print/mp-letter

USE_IMAKE=	yes
MAKE_FLAGS=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/man/man1 \
		XAPPLOADDIR=${PREFIX}/lib/X11/app-defaults  -f

.include <bsd.port.mk>
