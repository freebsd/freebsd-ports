# New ports collection makefile for:    lynx
# See http://www.wfbr.edu/dir/lynx/ for additional info
# Version required:     2.5
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.20 1996/03/09 06:00:09 ache Exp $
#

DISTNAME=       lynx2-5
PKGNAME=        lynx-2.5
CATEGORIES+=	www
MASTER_SITES=   ftp://ftp.kiae.su/unix/tcpip/internet/www/
EXTRACT_SUFX=   .zip

# Original location, lynx changes too often there
#MASTER_SITES=   http://www.wfbr.edu/lynx/
#NCFTP=          w3c
#NCFTPFLAGS=     -to multipart/x-zip -timeout 300 -o ${DISTFILES}
#FETCH_DEPENDS=  ${NCFTP}:${PORTSDIR}/www/comline

# FTP mirror of original location. Beware ugly VMS names
#NCFTPFLAGS=     -c
#MASTER_SITES=   ftp://ftp.hhs.dk//fote_mirror/
#NCFTPTAIL=      > ${DISTFILES}

MAINTAINER=	ache@FreeBSD.ORG

BUILD_DEPENDS=  ${EXTRACT_CMD}:${PORTSDIR}/archivers/unzip

WRKSRC=         ${WRKDIR}/lynx2-5
EXTRACT_CMD=    unzip
EXTRACT_ARGS=   -q
ALL_TARGET=     freebsd-ncurses

.include <bsd.port.mk>
