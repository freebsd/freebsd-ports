# New ports collection makefile for: netscape-communcator-linux-4.x
# Version required:		4.7
# Date created:			27 June 1999
# Whom:				girgen@partitur.se
# Based on work by:		thepish
#
# $FreeBSD$
#

DISTNAME=	linux-netscape-communicator-${BROWSER_VER}
CATEGORIES=	www linux
MASTER_SITES=	ftp://ftp.netscape.com/pub/communicator/english/4.72/unix/supported/linux20_glibc2/complete_install/ \
		ftp://ftp.sunet.se/pub/www/Netscape/communicator/english/4.72/unix/supported/linux20_glibc2/complete_install/
DISTFILES=	communicator-v472-export.x86-unknown-linuxglibc2.0.tar.gz

MAINTAINER=	girgen@partitur.se

RUN_DEPENDS=	/compat/linux/lib/ld.so:${PORTSDIR}/emulators/linux_base

ONLY_FOR_ARCHS=	i386

# don't overwrite the native FreeBSD port's shell script wrapper in ${PREFIX}/bin
BROWSER=	communicator-linux

WRKSRC=		${WRKDIR}/communicator-v472.x86-unknown-linux2.0

# use fake shell REQ script, since we don't require X aout libs.
PKGREQ=		${.CURDIR}/pkg/REQ

MAILCAP=	${.CURDIR}/files/mailcap
NSUBDIR=	lib/netscape-linux

.include "../netscape47-communicator/Makefile"
