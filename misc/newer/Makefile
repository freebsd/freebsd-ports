# New ports collection makefile for:    newer
# Date created:         22 January 2006
# Whom:                 Jeffrey H. Johnson <CPE1704TKS@bellsouth.net>
#
# $FreeBSD$
#

PORTNAME=	newer
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.cwru.edu/pub/chet/
DISTFILES=	newer.c
EXTRACT_ONLY=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An implementation of AT&T Research UNIX V8 newer(1)

CONFLICTS=	teTeX-base-[0-9]* tex-[0-9]* ja-ptex-base-*

PLIST_FILES=	bin/newer
NO_EXTRACT=	yes

do-build:
	${CP} ${DISTDIR}/newer.c ${WRKDIR}/newer.c
	${CC} ${CFLAGS} -o ${WRKDIR}/newer ${WRKDIR}/newer.c

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/newer ${PREFIX}/bin

.include <bsd.port.mk>
