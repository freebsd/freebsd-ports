# New ports collection makefile for:   wmtime
# Version required:    1.0b2
# Date created:        1 July 1998
# Whom:                Rich Neswold <rneswold@mcs.net>
#
# $Id$
#

DISTNAME=	wmtime-1.0b2
CATEGORIES=	x11
MASTER_SITES=	http://www.xs4all.nl/~warp/files/

MAINTAINER=	rneswold@mcs.net

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/wmtime.app/wmtime
USE_IMAKE=	yes
NO_INSTALL_MANPAGES= 1

post-extract:
	${CP} ${WRKSRC}/../Imakefile ${WRKSRC}/Imakefile

.include <bsd.port.mk>
