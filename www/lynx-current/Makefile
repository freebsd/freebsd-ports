# New ports collection makefile for:    lynx
# http://www.crl.com/~subir/lynx.html
# http://www.wfbr.edu/dir/lynx/
# Version required:     2.7
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.36 1997/02/04 10:17:14 ache Exp $
#

DISTNAME=       lynx2-7
PKGNAME=        lynx-2.7
CATEGORIES=	www
MASTER_SITES=   http://www.slcc.edu/lynx/fote/ \
		http://www.wfbr.edu/lynx/
DISTFILES=      lynx2-7.zip 27bugfixes.zip

MAINTAINER=	ache@FreeBSD.ORG

BUILD_DEPENDS=  unzip:${PORTSDIR}/archivers/unzip

WRKSRC=         ${WRKDIR}/lynx2-7
EXTRACT_CMD=    unzip
EXTRACT_ARGS=   -q -u -o
ALL_TARGET=     freebsd-ncurses
MAN1=		lynx.1

.include <bsd.port.mk>
