# New ports collection makefile for: netscape (communicator suite)
# Version required:	4.6*
# Date created:		24 Feb 1997
# Whom:			thepish
#
# $Id$
#

MASTER_SITES?=	ftp://ftp.netscape.com/pub/communicator/4.6/english/unix/unsupported/freebsd/complete_install/
DISTFILES?=	communicator-v46-export.x86-unknown-freebsd.tar.gz

MAINTAINER=	thepish@FreeBSD.ORG

MASTERDIR=	${.CURDIR}/../netscape4-communicator
NO_LATEST_LINK=	yes
WRKSRC=		${WRKDIR}/${BROWSER}-v46.x86-unknown-freebsd

BROWSER_VER=	4.6
INFILE_HEAD?=	'Communicator,4.6.0.99124'
NO_AUTOADMIN=	yes
NO_FORTIFY=	yes

.include "${MASTERDIR}/Makefile"
