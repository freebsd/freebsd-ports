# New ports collection makefile for:	cvsup-bin
# Version required:	16.1
# Date created:		12 November 1997
# Whom:			Sheldon Hearn <axl@iafrica.com>
#
# $FreeBSD$
#

DISTNAME=	cvsup-bin-16.1
CATEGORIES=	devel net
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/development/CVSup/binaries/

MAINTAINER=	jdp@freebsd.org

.if ${MACHINE_ARCH} == "i386"
DISTFILES=	cvsup-freebsd-ix86-${PORTOBJFORMAT}-16.1${EXTRACT_SUFX}
.else
DISTFILES=	cvsup.nogui-freebsd-${MACHINE_ARCH}-16.1${EXTRACT_SUFX}
WRKSRC=		${WRKDIR}/cvsup.nogui-bin-16.1
.endif

NO_BUILD=	yes

MAN1=		cvpasswd.1 cvsup.1
MANCOMPRESSED=	yes
NOT_FOR_ARCHS=	alpha
STRIP=

do-install:
	cd ${WRKSRC}; \
	    ${INSTALL_PROGRAM} cvpasswd cvsup ${PREFIX}/bin
.for file in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${file}.gz ${PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
