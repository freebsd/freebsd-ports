# New ports collection makefile for:    lynx
# http://www.crl.com/~subir/lynx.html
# http://www.wfbr.edu/dir/lynx/
# Version required:     2.6fm
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.34 1997/01/05 17:02:22 ache Exp $
#

DISTNAME=       lynx2-6fm
PKGNAME=        lynx-2.6fm
CATEGORIES=	www
MASTER_SITES=   http://www.slcc.edu/lynx/fote/ \
		http://www.wfbr.edu/lynx/
EXTRACT_SUFX=	.zip

MAINTAINER=	ache@FreeBSD.ORG

BUILD_DEPENDS=  unzip:${PORTSDIR}/archivers/unzip

WRKSRC=         ${WRKDIR}/lynx2-6FM
EXTRACT_CMD=    unzip
EXTRACT_ARGS=   -q -o
ALL_TARGET=     freebsd-ncurses
MAN1=		lynx.1

.include <bsd.port.mk>
