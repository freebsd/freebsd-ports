# New ports collection makefile for:	cvsup-bin
# Date created:		12 November 1997
# Whom:			Sheldon Hearn <axl@iafrica.com>
#
# $FreeBSD$
#

PORTNAME=	cvsup-bin
PORTVERSION=	16.1
CATEGORIES=	net devel
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/development/CVSup/binaries/

MAINTAINER=	jdp@freebsd.org

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "i386"
DISTFILES=	cvsup-freebsd-ix86-${PORTOBJFORMAT}-16.1${EXTRACT_SUFX}
.else
.if ${OSVERSION} >= 400011
DISTFILES=	cvsup-freebsd4-${MACHINE_ARCH}-16.1${EXTRACT_SUFX}
.else
BROKEN=		Not supported for pre-4.0 FreeBSD/Alpha versions
.endif
.endif

NO_BUILD=	yes

MAN1=		cvpasswd.1 cvsup.1
MANCOMPRESSED=	yes
STRIP=

do-install:
	cd ${WRKSRC}; \
	    ${INSTALL_PROGRAM} cvpasswd cvsup ${PREFIX}/bin
.for file in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${file}.gz ${PREFIX}/man/man1
.endfor

.include <bsd.port.post.mk>
