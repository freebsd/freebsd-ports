# New ports collection makefile for:    hp2xx
# Version required:     3.20
# Date created:         17 Jan 1999
# Whom:                 Lars Koeller
#
# $Id$
#

DISTNAME=	hp2xx-3.20-png
PKGNAME=	hp2xx-3.20
CATEGORIES=	print x11
MASTER_SITES=	ftp://ftp.rz.uni-duesseldorf.de/pub/graphics/ \
		ftp://ftp.uni-bielefeld.de/pub/systems/FreeBSD/lkoeller/

MAINTAINER=	Lars.Koeller@Uni-Bielefeled.DE

LIB_DEPENDS=    png.3:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/${DISTNAME}/sources
USE_XLIB=	yes
MAKEFILE=	makefile
MAN1=		hp2xx.1

post-install:
	if [ ! -f ${PREFIX}/info/dir ]; then \
		${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
.for info in hp2xx.info
	install-info ${PREFIX}/info/${info} ${PREFIX}/info/dir
.endfor

.include <bsd.port.mk>
