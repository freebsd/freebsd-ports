# New ports collection makefile for:	knews
# Version required:     0.9.3
# Date created:         Sat Nov 18 15:23:47 MET 1995
# Whom:                 Andreas Klemm <andreas@knobel.gun.de>
#
#

DISTNAME=	knews-0.9.3
PKGNAME=	knews-0.9.3
CATEGORIES+=	x11
CATEGORIES+=	news
MASTER_SITES+=	ftp://sunsite.unc.edu/pub/Linux/X11/xapps/networked/
MASTER_SITES+=	ftp://ftp.cc.gatech.edu/ac88/linux/X11/xapps/networked/
MASTER_SITES+=	ftp://ftp.germany.eu.net/pub/os/Linux/Mirror.SunSITE/X11/xapps/networked/
MASTER_SITES+=	ftp://ftp.funet.fi/pub/mirrors/sunsite.unc.edu/pub/Linux/X11/xapps/networked/

# perhaps Andreas is going to maintain it personally some day... :)
#MAINTAINER=	andreas@knobel.gun.de
MAINTAINER=	joerg

USE_IMAKE=	yes
MAKE_FLAGS=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/man/man1 \
		XAPPLOADDIR=${PREFIX}/lib/X11/app-defaults  -f

IS_INTERACTIVE=	no

.include <bsd.port.mk>
