# New ports collection makefile for:    xcopilot
# Version required:     0.4
# Date created:         July 17 1997
# Whom:                 Nick Sayer <nsayer@quack.kfu.com>
#
# $Id:$
#

DISTNAME=       xcopilot-v0.4
PKGNAME=	xcopilot-0.4iang8
CATEGORIES=     emulators
MASTER_SITES=   ftp://uiarchive.cso.uiuc.edu/pub/systems/PalmOS/
PATCHFILES=	xcopilot-v0.4-iang8.diff
PATCH_DIST_STRIP= -p1
PATCH_SITES=	http://www.isaac.cs.berkeley.edu/pilot/

MAINTAINER=     nsayer@quack.kfu.com

USE_X11=	yes
LIB_DEPENDS=    Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

.include <bsd.port.mk>
