# New ports collection makefile for:    tclock
# Date created:		So   7 Feb 1999 20:50:43 MET
# Whom:			Lars Koeller <lkoeller@cc.fh-lippe.de>
#
# $FreeBSD$
#

PORTNAME=	tclock
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	x11-clocks
MASTER_SITES=	ftp://ftp.uni-potsdam.de/pub/X11/tools/clocks/		\
		ftp://ftp.uni-bielefeld.de/pub/systems/FreeBSD/lkoeller/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Transparent analog clock for x11

NO_WRKSUBDIR=	yes
USE_IMAKE=	yes
USE_XORG=	x11 xext
MAN1=		tclock.1
PLIST_FILES=	bin/tclock

.include <bsd.port.mk>
