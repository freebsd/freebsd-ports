# New ports collection makefile for:    lynx
# See http://www.wfbr.edu/dir/lynx/ for additional info
# Version required:     2.4-FM
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.15 1995/12/16 04:07:45 ache Exp $
#

DISTNAME=       lynx2-4-FM
PKGNAME=        lynx-2.4fm
CATEGORIES+=	www

# Original location, lynx changes too often there
#MASTER_SITES=   http://www.wfbr.edu/lynx/
#NCFTP=          w3c
#NCFTPFLAGS=     -to multipart/x-zip -timeout 120 -o ${DISTFILES}
#FETCH_DEPENDS=  ${NCFTP}:${PORTSDIR}/www/comline

MASTER_SITES=   ftp://ftp.kiae.su/unix/tcpip/nidr/www/
DISTFILES=      lynx2-4-fm.zip
EXTRACT_CMD=    unzip
EXTRACT_ARGS=   -q

MAINTAINER=	ache@FreeBSD.ORG

BUILD_DEPENDS=  ${EXTRACT_CMD}:${PORTSDIR}/archivers/unzip

ALL_TARGET=     freebsd-ncurses

.include <bsd.port.mk>
