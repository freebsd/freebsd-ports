# New ports collection makefile for:    lynx
# See http://www.wfbr.edu/dir/lynx/ for additional info
# Version required:     2.4-FM
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.19 1996/02/29 10:29:37 asami Exp $
#

DISTNAME=       lynx2-4-fm
PKGNAME=        lynx-2.4fm
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

WRKSRC=         ${WRKDIR}/lynx2-4-FM
EXTRACT_CMD=    unzip
EXTRACT_ARGS=   -q
ALL_TARGET=     freebsd-ncurses

.include <bsd.port.mk>
