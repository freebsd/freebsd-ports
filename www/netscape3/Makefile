# New ports collection makefile for:	netscape
# Date created:		21 August 1995
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME?=	netscape
PORTVERSION?=	3.04
CATEGORIES=	www
MASTER_SITES?=	ftp://archive:oldies@archive.netscape.com/archive/navigator/3.04/shipping/english/unix/bsdi11/navigator_complete/
DISTFILES=	netscape-v304-export.x86-unknown-bsd.tar.gz

MAINTAINER=	sada@FreeBSD.org

RUN_DEPENDS=	${X11BASE}/lib/aout/libX11.so.6.1:${PORTSDIR}/x11/XFree86-aoutlibs

ONLY_FOR_ARCHS=	i386

USE_XLIB=	yes
NO_LATEST_LINK=	yes
NO_WRKSUBDIR=	yes
PKGREQ=		${PORTSDIR}/www/netscape4-communicator/pkg-req.aout

.if defined(WITH_128BIT)
MASTER_SITES+=	ftp://ftp.fortify.net/pub/Fortify/ \
		ftp://ftp.za.freebsd.org/pub/Fortify/
DISTFILES+=	${FORTIFY}.tar.gz
RESTRICTED=	"Contains strong cryptography"
.endif

FORTIFY=	Fortify-1.4.6-unix-x86

.if !defined(WITH_128BIT)
pre-extract:
		@${ECHO} "You can make Netscape use 128-bit encryption by defining WITH_128BIT"
		@${ECHO} "and defining USA_RESIDENT to NO"
.endif

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGREQ} ${PKGNAME} INSTALL

post-install:
.if defined(WITH_128BIT)
	cd ${WRKDIR}/${FORTIFY} \
	&& (${ECHO}; ${ECHO} yes; ${ECHO} no; ${ECHO} no) \
	| ./Fortify.sh ${PREFIX}/lib/netscape/netscape.bin
.endif
	@${CAT} ${DESCR}

.include <bsd.port.mk>
