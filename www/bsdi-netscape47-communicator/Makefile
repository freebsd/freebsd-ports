# New ports collection makefile for: netscape (communicator suite)
# Version required:	4.7
# Date created:		24 Feb 1997
# Whom:			thepish
#
# $FreeBSD$
#

MASTER_SITES?=	ftp://ftp.netscape.com./pub/communicator/english/4.7/unix/unsupported/freebsd/complete_install/
DISTFILES?=	communicator-v47-export.x86-unknown-freebsd.tar.gz

MASTERDIR=	${.CURDIR}/../netscape4-communicator
NO_LATEST_LINK=	yes
WRKSRC?=	${WRKDIR}/${BROWSER}-v47.x86-unknown-freebsd

BROWSER_VER=	4.7
INFILE_HEAD?=	'Communicator,4.7.0.19990915'
NO_AUTOADMIN=	yes

.include "${MASTERDIR}/Makefile"
