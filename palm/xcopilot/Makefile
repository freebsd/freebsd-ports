# New ports collection makefile for:    xcopilot
# Version required:     0.4
# Date created:         July 17 1997
# Whom:                 Nick Sayer <nsayer@quack.kfu.com>
#
# $Id: Makefile,v 1.6 1998/09/17 00:32:31 asami Exp $
#

DISTNAME=       xcopilot-v0.4
PKGNAME=	xcopilot-0.4.8
CATEGORIES=     palm emulators
MASTER_SITES=   ftp://uiarchive.cso.uiuc.edu/pub/systems/PalmOS/

PATCH_SITES=	http://www.isaac.cs.berkeley.edu/pilot/
PATCHFILES=	xcopilot-v0.4-iang8.diff
PATCH_DIST_STRIP= -p1

MAINTAINER=     nsayer@quack.kfu.com

LIB_DEPENDS=    Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes

.include <bsd.port.mk>
