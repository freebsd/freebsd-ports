# New ports collection makefile for:	cvsupd-bin
# Date created:		17 August 1998
# Whom:			Sheldon Hearn <axl@iafrica.com>
#
# $FreeBSD$
#

PORTNAME=	cvsupd-bin
PORTVERSION=	16.1
CATEGORIES=	net devel
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/development/CVSup/binaries/

MAINTAINER=	jdp@freebsd.org

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "i386"
DISTFILES=	cvsupd-freebsd-ix86-${PORTOBJFORMAT}-16.1${EXTRACT_SUFX}
.else
.if ${OSVERSION} >= 400011
DISTFILES=	cvsupd-freebsd4-${MACHINE_ARCH}-16.1${EXTRACT_SUFX}
.else
BROKEN=		Not supported for pre-4.0 FreeBSD/Alpha versions
.endif
.endif

NO_BUILD=	yes

MAN8=	cvsupd.8
MANCOMPRESSED=	yes
STRIP=

do-install:
	cd ${WRKSRC}; \
	    ${INSTALL_PROGRAM} cvsupd ${PREFIX}/sbin; \
	    ${INSTALL_MAN} ${MAN8}.gz ${PREFIX}/man/man8

.include <bsd.port.post.mk>
