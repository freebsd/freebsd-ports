# ports collection makefile for: Clipboard
# Date created:      28 Jun 1997
# Whom:              Ruslan Shevchenko <ruslan@shevchenko.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	offix-printer
PORTVERSION=	2.4
PORTREVISION=	1
CATEGORIES=	print offix
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	desktop_managers/OffiX
DISTNAME=	Printer-2.4

MAINTAINER=	ruslan@shevchenko.kiev.ua
COMMENT=	OffiX printer icon with support of DND protocol

LIB_DEPENDS=	Dnd.1:${PORTSDIR}/x11/libdnd

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X_PREFIX=	YES
USE_XPM=	YES
MAN1=		printer.1

.include <bsd.port.mk>
