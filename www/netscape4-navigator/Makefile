# New ports collection makefile for:	netscape (navigator only)
# Version required:     4.08
# Date created:         24 Feb 1997
# Whom:                 ache
#
# $Id$
#

MASTER_SITES=	ftp://ftp.netscape.com/pub/communicator/${BROWSER_VER}/english/unix/unsupported/freebsd/navigator_standalone/
DISTFILES=	navigator-v408-export.x86-unknown-freebsd.tar.gz

MAINTAINER=     sada@FreeBSD.ORG

MASTERDIR=	${.CURDIR}/../netscape4-communicator
FILESDIR=	${.CURDIR}/files
PKGDIR=		${.CURDIR}/pkg
PKGREQ=		${MASTERDIR}/pkg/REQ

BROWSER=	navigator
INFILE_HEAD=	'Navigator,4.08.0.98306'

.include "${MASTERDIR}/Makefile"
