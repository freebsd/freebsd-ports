# New ports collection makefile for:    lynx
# See http://www.wfbr.edu/dir/lynx/ for additional info
# Version required:     2.4-FM
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.16 1996/01/16 03:43:25 ache Exp $
#

DISTNAME=       lynx2-4-FM
PKGNAME=        lynx-2.4fm
CATEGORIES+=	www

# Original location, lynx changes too often there
#MASTER_SITES=   http://www.wfbr.edu/lynx/
#NCFTP=          w3c
#NCFTPFLAGS=     -to multipart/x-zip -timeout 120 -o ${DISTFILES}
#FETCH_DEPENDS=  ${NCFTP}:${PORTSDIR}/www/comline

# Beware ugly VMS names
NCFTPFLAGS=     -c
MASTER_SITES=   ftp://ftp.hhs.dk//fote_mirror/
DISTFILES=      lynx2-4-fm.zip
NCFTPTAIL=      > ${DISTFILES}

EXTRACT_CMD=    unzip
EXTRACT_ARGS=   -q

MAINTAINER=	ache@FreeBSD.ORG

BUILD_DEPENDS=  ${EXTRACT_CMD}:${PORTSDIR}/archivers/unzip

ALL_TARGET=     freebsd-ncurses

.include <bsd.port.mk>
