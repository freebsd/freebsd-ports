# New ports collection makefile for: netscape-communcator-linux-4.x
# Version required:		4.7
# Date created:			27 June 1999
# Whom:				girgen@partitur.se
# Based on work by:		thepish
#
# $FreeBSD$
#

DISTNAME=	linux-netscape-${BROWSER}-${BROWSER_VER}
MASTER_SITES=	ftp://ftp.netscape.com/pub/communicator/english/4.7/unix/supported/linux20_glibc2/complete_install/ \
		ftp://ftp.sunet.se/pub/www/Netscape/communicator/english/4.7/unix/supported/linux20_glibc2/complete_install/
DISTFILES=	communicator-v47-export.x86-unknown-linuxglibc2.0.tar.gz

MAINTAINER=	girgen@partitur.se

RUN_DEPENDS=	/compat/linux/lib/ld.so:${PORTSDIR}/emulators/linux_base

WRKSRC=		${WRKDIR}/${BROWSER}-v47.x86-unknown-linux2.0

MAILCAP=	${.CURDIR}/files/mailcap
NSUBDIR=	lib/netscape-linux

.include "../netscape47-communicator/Makefile"
