# New ports collection makefile for:	boxes
# Date created:				3 March 2000
# Whom:					Patrick Seal (patseal@hyperhost.net)
#
# $FreeBSD$
#

PORTNAME=	boxes
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://boxes.thomasjensen.com/download/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/text
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Draws ASCII-art configurable boxes around text or code

MAN1=		boxes.1
USE_GMAKE=	yes
USE_BISON=	yes
ALL_TARGET=	boxes
MAKE_ARGS=	CC="${CC}" GLOBALCONF=${GLOBALCONF} CFLAGS="${CFLAGS} -ansi -I. -Iregexp"

GLOBALCONF=	${DATADIR}/boxes-config
PLIST_FILES=	bin/boxes share/boxes/boxes-config
PLIST_DIRS=	share/boxes

do-configure:
	${RM} ${WRKSRC}/src/boxes.h ${WRKSRC}/doc/boxes.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/boxes ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/boxes-config ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/doc/${MAN1} ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
