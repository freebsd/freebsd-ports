# New ports collection makefile for:	boxes
# Date created:				3 March 2000
# Whom:					Patrick Seal (patseal@hyperhost.net)
#
# $FreeBSD$
#

PORTNAME=	boxes
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	http://www6.informatik.uni-erlangen.de/~tsjensen/software/boxes/download/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=    utils/text
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	patseal@hyperhost.net

MAN1=		boxes.1
USE_GMAKE=	yes
ALL_TARGET=

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/boxes ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/boxes
	${INSTALL_DATA} ${WRKSRC}/boxes-config ${PREFIX}/share/boxes
	${INSTALL_MAN} ${WRKSRC}/doc/$(MAN1) ${PREFIX}/man/man1

.include <bsd.port.mk>
