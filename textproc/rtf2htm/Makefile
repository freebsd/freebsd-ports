# ex:ts=8
# New ports collection makefile for:	rtf2htm
# Date created:			Sep 3, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	rtf2htm
PORTVERSION=	0.17.1
CATEGORIES=	textproc
MASTER_SITES=	http://www.geocities.com/tuorfa/

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKEFILE=	makefile

MANCOMPRESSED=	no
MAN1=	rtf2htm.1

post-patch:
	@${REINPLACE_CMD} -e "s,^CC,#CC,g ; s,^CFLAGS,#CFLAGS,g" ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/malloc.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rtf2htm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
