# New ports collection makefile for:    lynx
# See http://www.wfbr.edu/dir/lynx/ for additional info
# Version required:     2.5FM
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.21 1996/05/03 19:48:58 ache Exp $
#

DISTNAME=       lynx2-5FM
PKGNAME=        lynx-2.5FM
CATEGORIES+=	www
MASTER_SITES=   ftp://ftp.more.net/pub/mirrors/lynx/

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

ALL_TARGET=     freebsd-ncurses

.include <bsd.port.mk>
