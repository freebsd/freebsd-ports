# Created by: ijliao
# $FreeBSD$

PORTNAME=	floatator
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://floatator.cichon.com/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive fluid dynamics simulation

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTCOUT=	skipv:0.9.1
USES=		motif
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DNDEBUG" \
		X11INCLUDE="-I${LOCALBASE}/include" X11LIB="-L${LOCALBASE}/lib"
PLIST_FILES=	bin/floatator bin/floatator_X_interface

do-install:
.for f in floatator floatator_X_interface
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
