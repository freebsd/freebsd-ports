# New ports collection makefile for:   abs
# Version required:    0.5
# Date created:        20 January 1999
# Whom:                gmarco
#
# $Id$
#

DISTNAME=	abs-src-0.5
PKGNAME=	abs-0.5
CATEGORIES=	math
MASTER_SITES=	http://www.ping.be/bertin/

MAINTAINER=	freebsd@scotty.masternet.it

USE_XLIB=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abs ${PREFIX}/bin

.include <bsd.port.mk>
