# New ports collection makefile for: netscape-communcator-linux-4.x
# Date created:			27 June 1999
# Whom:				girgen@partitur.se
# Based on work by:		thepish
#
# $FreeBSD$
#

PORTNAME=	linux-netscape-${BROWSER}
PORTVERSION=	${BROWSER_VER}
CATEGORIES=	www linux
MASTER_SITES=	ftp://ftp.netscape.com/pub/communicator/english/4.73/unix/supported/linux20_glibc2/complete_install/ \
		ftp://ftp.sunet.se/pub/www/Netscape/communicator/english/4.73/unix/supported/linux20_glibc2/complete_install/ \
		ftp://ftp.netscape.com/pub/communicator/english/4.73/unix/supported/linux20_glibc2/navigator_standalone/ \
		ftp://ftp.sunet.se/pub/www/Netscape/communicator/english/4.73/unix/supported/linux20_glibc2/navigator_standalone/
DISTFILES=	${BROWSER}-v473-export.x86-unknown-linuxglibc2.0.tar.gz

MAINTAINER=	girgen@partitur.se

RUN_DEPENDS=	/compat/linux/lib/ld.so:${PORTSDIR}/emulators/linux_base \
		netscape:${PORTSDIR}/www/netscape-wrapper

ONLY_FOR_ARCHS=	i386

# don't overwrite the native FreeBSD port's shell script wrapper in ${PREFIX}/bin
BROWSER_ARC=	${BROWSER}-linux

WRKSRC=		${WRKDIR}/${BROWSER}-v473.x86-unknown-linux2.0

USE_LINUX_LIB=	yes

MAILCAP=	${.CURDIR}/../linux-netscape47-communicator/files/mailcap
NSUBDIR=	lib/netscape-linux

.include "../netscape47-communicator/Makefile"
