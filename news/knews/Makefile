# New ports collection makefile for:	knews
# Version required:     0.9.8
# Date created:         Sun Apr 14 09:23:59 MET DST 1996
# Whom:                 Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.23 1999/01/07 20:37:40 andreas Exp $
#

DISTNAME=	knews-1.0b.1
CATEGORIES=	news
MASTER_SITES=	http://www.matematik.su.se/~kjj/

MAINTAINER=	andreas@FreeBSD.ORG

LIB_DEPENDS=    Xpm.4:${PORTSDIR}/graphics/xpm \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.3:${PORTSDIR}/graphics/png
RUN_DEPENDS=    newsp:${PORTSDIR}/print/mp-letter

USE_IMAKE=	yes
MAKE_FLAGS=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/man/man1 \
		XAPPLOADDIR=${PREFIX}/lib/X11/app-defaults  -f

.include <bsd.port.mk>
