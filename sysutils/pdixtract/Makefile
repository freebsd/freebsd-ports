# New ports collection makefile for:	pdixtract
# Date created:				Mon Jul  4 23:21:23 CEST 2005
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pdixtract
PORTVERSION=	1.5
CATEGORIES=	sysutils
MASTER_SITES=	http://members.chello.se/jonas.thornqvist/
DISTNAME=	PDITOOL

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Extracts or converts .pdi file sets to .iso

USE_ZIP=	yes

PLIST_FILES=	bin/pdixtract

do-build:
	cd ${WRKDIR}; ${CC} ${CFLAGS} pdixtract.c -o pdixtract

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/pdixtract ${PREFIX}/bin

.include <bsd.port.mk>
