# New ports collection makefile for:    lynx
# http://www.nyu.edu/pages/wsn/subir/lynx.html
# http://www.wfbr.edu/dir/lynx/
# Version required:     2.6
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.25 1996/10/03 20:44:49 ache Exp $
#

DISTNAME=       lynx2-6
PKGNAME=        lynx-2.6
CATEGORIES+=	www
MASTER_SITES=   http://www.wfbr.edu/lynx/ \
		ftp://ftp.more.net/pub/mirrors/lynx/
EXTRACT_SUFX=   .zip

PATCH_SITES=    http://www.nyu.edu/pages/wsn/subir/lynx/patches/
PATCHFILES=     2-6-patch1.txt 2-6-patch2.txt 2-6-patch3.txt 2-6-patch4.txt \
		2-6-patch5.txt
PATCH_DIST_STRIP= -p1 -l

MAINTAINER=	ache@FreeBSD.ORG

BUILD_DEPENDS=  unzip:${PORTSDIR}/archivers/unzip

EXTRACT_CMD=    unzip
EXTRACT_ARGS=   -q

ALL_TARGET=     freebsd-ncurses

.include <bsd.port.mk>
