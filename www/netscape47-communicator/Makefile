# New ports collection makefile for: netscape (communicator suite)
# Version required:	4.7
# Date created:		24 Feb 1997
# Whom:			thepish
#
# $FreeBSD$
#

.if !defined(PRE_MK_INCLUDED)
.include <bsd.port.pre.mk>
.endif

.if ${ARCH} == "i386"
MASTER_SITES?=	ftp://ftp.netscape.com./pub/communicator/english/4.7/unix/unsupported/freebsd/complete_install/
DISTFILES?=	communicator-v47-export.x86-unknown-freebsd.tar.gz
.elif ${ARCH} == "alpha"
MASTER_SITES?=	ftp://ftp.netscape.com./pub/communicator/english/4.7/unix/supported/dec_unix40/complete_install/
DISTFILES?=	communicator-v47-export.alpha-dec-osf4.0.tar.gz
.endif

ONLY_FOR_ARCHS=	i386 alpha

MASTERDIR=	${.CURDIR}/../netscape4-communicator
NO_LATEST_LINK=	yes
.if ${ARCH} == "i386"
WRKSRC?=	${WRKDIR}/${BROWSER}-v47.x86-unknown-freebsd
.elif ${ARCH} == "alpha"
WRKSRC?=	${WRKDIR}/${BROWSER}-v47.alpha-dec-osf4.0
.endif

BROWSER_VER=	4.7
INFILE_HEAD?=	'Communicator,4.7.0.19990915'
NO_AUTOADMIN=	yes

PRE_MK_INCLUDED=	yes
.include "${MASTERDIR}/Makefile"
