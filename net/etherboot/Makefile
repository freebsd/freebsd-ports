# New ports collection makefile for:   etherboot
# Date created:        16 April 1999
# Whom:                Doug Ambrisko <ambrisko@whistle.com>
#
# $FreeBSD$
#

PORTNAME=	etherboot
PORTVERSION=	4.5.5
CATEGORIES=	net
MASTER_SITES=	http://www.slug.org.au/etherboot/ \
		http://www.us.kernel.org/pub/linux/devel/gcc/ \
		http://www.ambrisko.com/doug/
DISTFILES=	${DISTNAME}.tar.gz ${BINUTILS_VER}.tar.gz

MAINTAINER=	ambrisko@whistle.com

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

NO_PACKAGE=	lots of configuration necessary
USE_GMAKE=1
WRKSRC=		${WRKDIR}/${DISTNAME}/src
BINUTILS_VER=   binutils-2.9.1.0.25  # need newer version of gas for data32

pre-configure:
	cd ${WRKDIR}/${BINUTILS_VER} ; \
	   ./configure -host=i386-unknown-freebsdelf

pre-build:
	cd ${WRKDIR}/${BINUTILS_VER} ; \
	make

do-install:
	@${ECHO} Refer ${PKGDIR}/DESCR and ${WRKDIR}/${PKGNAME}/doc for how to
	@${ECHO} build and install the rom/floppy image.
	@exit 1

.include <bsd.port.mk>
