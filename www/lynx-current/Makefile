# New ports collection makefile for:    lynx
# See http://www.wfbr.edu/dir/lynx/ for additional info
# Version required:     2.6
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.22 1996/05/18 23:05:04 ache Exp $
#

DISTNAME=       lynx2-6
PKGNAME=        lynx-2.6
CATEGORIES+=	www
MASTER_SITES=   http://www.wfbr.edu/lynx/ \
		ftp://ftp.more.net/pub/mirrors/lynx/
EXTRACT_SUFX=   .zip

MAINTAINER=	ache@FreeBSD.ORG

BUILD_DEPENDS=  unzip:${PORTSDIR}/archivers/unzip
EXTRACT_CMD=    unzip
EXTRACT_ARGS=   -q

ALL_TARGET=     freebsd-ncurses

.include <bsd.port.mk>
