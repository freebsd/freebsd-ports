# ex:ts=8
# Ports collection makefile for:	floatator
# Date created:			Jun 1, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	floatator
PORTVERSION=	0.2.1
CATEGORIES=	misc
MASTER_SITES=	http://floatator.cichon.com/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interactive fluid dynamics simulation

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_MOTIF=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DNDEBUG" \
		X11INCLUDE="-I${X11BASE}/include" X11LIB="-L${X11BASE}/lib"
PLIST_FILES=	bin/floatator bin/floatator_X_interface

do-install:
.for f in floatator floatator_X_interface
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
