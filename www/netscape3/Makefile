# New ports collection makefile for:	netscape
# Version required:     3.04
# Date created:		21 August 1995
# Whom:			asami
#
# $FreeBSD$
#

DISTNAME?=	netscape-3.04
CATEGORIES=	www
MASTER_SITES?=   ftp://archive:oldies@archive.netscape.com/archive/navigator/3.04/shipping/english/unix/bsdi11/navigator_complete/
DISTFILES=      netscape-v304-export.x86-unknown-bsd.tar.gz

MAINTAINER=	sada@FreeBSD.org

Y2K=		http://home.netscape.com/products/year2000/faq/client.html

ONLY_FOR_ARCHS=	i386

USE_XLIB=	yes
NO_LATEST_LINK=	yes
NO_WRKSUBDIR=	yes
PKGREQ=		${PORTSDIR}/www/netscape4-communicator/pkg/REQ

.if defined(USE_128BIT)
MASTER_SITES+=	ftp://ftp.fortify.net/pub/Fortify/ \
		ftp://ftp.za.freebsd.org/pub/Fortify/
DISTFILES+=	${FORTIFY}.tar.gz
RESTRICTED=     "Contains strong cryptography"
.endif

FORTIFY=	Fortify-1.4.5-unix-x86

.if !defined(USE_128BIT)
pre-extract:
		@${ECHO} "You can make Netscape use 128-bit encryption by defining USE_128BIT"
		@${ECHO} "and defining USA_RESIDENT to NO"
.endif

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGREQ} ${PKGNAME} INSTALL

post-install:
.if defined(USE_128BIT)
	cd ${WRKDIR}/${FORTIFY} \
	&& (${ECHO}; ${ECHO} yes; ${ECHO} no; ${ECHO} no) \
	| ./Fortify.sh ${PREFIX}/lib/netscape/netscape.bin
.endif
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
