# New ports collection makefile for:    lynx
# Version required:     2.4-FM
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.12 1995/11/27 04:10:25 asami Exp $
#

DISTNAME=       lynx2-4-FM
PKGNAME=        lynx-2.4fm
CATEGORIES+=	www
MASTER_SITES=   http://www.wfbr.edu/lynx/
DISTFILES=      lynx2-4-fm.zip
NCFTP=          w3c
NCFTPFLAGS=     -to multipart/x-zip -timeout 60 -o ${DISTFILES}
EXTRACT_CMD=    unzip
EXTRACT_ARGS=   -q

MAINTAINER=	ache@FreeBSD.ORG

FETCH_DEPENDS=  ${NCFTP}:${PORTSDIR}/www/comline
BUILD_DEPENDS=  ${EXTRACT_CMD}:${PORTSDIR}/archivers/unzip

ALL_TARGET=     freebsd-ncurses

.include <bsd.port.mk>
