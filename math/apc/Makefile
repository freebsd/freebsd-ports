# New ports collection makefile for:	apc
# Version required:	1.0.1-beta
# Date created:		May 1 1997
# Whom:			Eric A. Griff <eagriff@global2000.net>
#
# $Id$
#

DISTNAME=	apc-1.0.1-beta
PKGNAME=	apc-1.0.1b
CATEGORIES= 	math
MASTER_SITES= 	http://members.global2000.net/~eagriff/

MAINTAINER= 	eagriff@global2000.net

LIB_DEPENDS=	xforms\\.0\\.86:${PORTSDIR}/x11/xforms

ALL_TARGET=	apc
USE_X11=	YES

do-install:
		@${INSTALL_PROGRAM} ${WRKSRC}/apc ${PREFIX}/bin/

.include <bsd.port.mk>
