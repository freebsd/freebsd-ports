# New ports collection makefile for: netscape (communicator suite)
# Date created:		24 Feb 1997
# Whom:			thepish
#
# $FreeBSD$
#

PORTNAME=	netscape-${BROWSER_ARC}
PORTVERSION=	${BROWSER_VER}

.if !defined(PRE_MK_INCLUDED)
.include <bsd.port.pre.mk>
.endif

.if ${ARCH} == "i386"
MASTER_SITES?=	ftp://ftp.netscape.com./pub/communicator/english/4.72/unix/unsupported/freebsd/complete_install/
DISTFILES?=	communicator-v472-export.x86-unknown-freebsd.tar.gz
.elif ${ARCH} == "alpha"
MASTER_SITES?=	ftp://ftp.netscape.com./pub/communicator/english/4.72/unix/supported/dec_unix40/complete_install/
DISTFILES?=	communicator-v472-export.alpha-dec-osf4.0.tar.gz
.endif

ONLY_FOR_ARCHS=	i386 alpha

MASTERDIR=	${.CURDIR}/../netscape4-communicator
.if ${ARCH} == "i386"
WRKSRC?=	${WRKDIR}/${BROWSER}-v472.x86-unknown-freebsd
.elif ${ARCH} == "alpha"
WRKSRC?=	${WRKDIR}/${BROWSER}-v472.alpha-dec-osf4.0
.endif

BROWSER_VER=	4.72
#	taken from ,${BLDVERS} in ns-install
INFILE_HEAD?=	'Communicator,4.72.0.20000131'
NO_AUTOADMIN=	yes

PRE_MK_INCLUDED=	yes
.include "${MASTERDIR}/Makefile"
