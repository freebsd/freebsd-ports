# ports collection makefile for: Clipboard
# Version required:  2.4
# Date created:      28 Jun 1997
# Whom:              Ruslan Shevchenko <ruslan@shevchenko.kiev.ua>
#
# $Id: Makefile,v 1.1.1.1 1998/05/06 12:30:47 tg Exp $
#

DISTNAME=	Printer-2.4
PKGNAME=	offix-printer-2.4
CATEGORIES=	print x11 offix
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	desktop_managers/OffiX

MAINTAINER=	ruslan@shevchenko.kiev.ua

LIB_DEPENDS=	Dnd\\.1\\.:${PORTSDIR}/x11/libdnd \
		Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X_PREFIX=	YES
MAN1=		printer.1

.include <bsd.port.mk>
