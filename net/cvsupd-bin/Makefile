# New ports collection makefile for:	cvsupd-bin
# Version required:	16.0
# Date created:		17 August 1998
# Whom:			Sheldon Hearn <axl@iafrica.com>
#
# $FreeBSD$
#

DISTNAME=	cvsupd-bin-16.0
CATEGORIES=	devel net
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/development/CVSup/binaries/

MAINTAINER=	jdp@freebsd.org

.if ${MACHINE_ARCH} == "i386"
DISTFILES=	cvsupd-freebsd-ix86-aout-16.0${EXTRACT_SUFX}
.else
DISTFILES=	cvsupd-freebsd-${MACHINE_ARCH}-16.0${EXTRACT_SUFX}
.endif

NO_BUILD=	yes

MAN8=	cvsupd.8
MANCOMPRESSED=	yes
STRIP=

do-install:
	cd ${WRKSRC}; \
	    ${INSTALL_PROGRAM} cvsupd ${PREFIX}/sbin; \
	    ${INSTALL_MAN} ${MAN8}.gz ${PREFIX}/man/man8

.include <bsd.port.mk>
