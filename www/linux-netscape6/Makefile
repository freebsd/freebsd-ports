# New ports collection makefile for: netscape-communcator-linux-4.61
# Version required:		4.61
# Date created:			27 June 1999
# Whom:				girgen@partitur.se
# Based on work by:		thepish
#
# $FreeBSD$
#

DISTNAME=	linux-netscape-${BROWSER}-${BROWSER_VER}
MASTER_SITES?=	ftp://ftp.netscape.com/pub/communicator/english/4.61/unix/supported/linux20_libc5/complete_install/
DISTFILES?=	communicator-v461-export.x86-unknown-linux2.0.tar.gz

MAINTAINER=	girgen@partitur.se

RUN_DEPENDS=	/compat/linux/usr/i486-linux-libc5/lib/libc.so.5:${PORTSDIR}/emulators/linux_base

WRKSRC=		${WRKDIR}/${BROWSER}-v461.x86-unknown-linux2.0

MAILCAP=	${.CURDIR}/files/mailcap
NSUBDIR?=	lib/netscape-linux

.include "../netscape46-communicator/Makefile"
