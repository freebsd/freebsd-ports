# New ports collection makefile for: linux-netscape47-navigator
# Version required:		4.72
# Date created:			Tue Mar  7 22:59:55 CET 2000
# Whom:				Dirk Froemberg <dirk@FreeBSD.org>
# Based on work by:		girgen@partitur.se
#
# $FreeBSD$
#

DISTNAME=	linux-netscape-navigator-${BROWSER_VER}
CATEGORIES=	www linux
MASTER_SITES=	ftp://ftp.netscape.com/pub/communicator/english/4.72/unix/supported/linux20_glibc2/complete_install/ \
		ftp://ftp.sunet.se/pub/www/Netscape/communicator/english/4.72/unix/supported/linux20_glibc2/complete_install/
DISTFILES=	navigator-v472-export.x86-unknown-linuxglibc2.0.tar.gz

MAINTAINER=	dirk@FreeBSD.org

RUN_DEPENDS=	/compat/linux/lib/ld.so:${PORTSDIR}/emulators/linux_base

ONLY_FOR_ARCHS=	i386

# don't overwrite the native FreeBSD port's shell script wrapper in ${PREFIX}/bin
BROWSER=	navigator-linux

WRKSRC=		${WRKDIR}/navigator-v472.x86-unknown-linux2.0

# use fake shell REQ script, since we don't require X aout libs.
PKGREQ=		${.CURDIR}/pkg/REQ

MAILCAP=	${.CURDIR}/files/mailcap
NSUBDIR=	lib/netscape-linux

.include "../netscape47-communicator/Makefile"
