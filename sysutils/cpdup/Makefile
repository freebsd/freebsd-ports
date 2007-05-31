# New ports collection makefile for:    cpdup
# Date created:         28 Oct 1999
# Whom:                 dillon
#
# $FreeBSD$
#

PORTNAME=	cpdup
PORTVERSION=	1.07
CATEGORIES=	sysutils
MASTER_SITES=	http://apollo.backplane.com/FreeBSDPorts/ \
		http://utenti.gufi.org/~gmarco/files/distfiles/

MAINTAINER=	gmarco@gufi.org
COMMENT=	A comprehensive filesystem mirroring and backup program

WRKSRC=		${WRKDIR}/${PORTNAME}

CFLAGS+=	-D_ST_FLAGS_PRESENT_

MAN1=		cpdup.1
PLIST_FILES=	bin/cpdup

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cpdup ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cpdup.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
