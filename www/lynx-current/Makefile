# New ports collection makefile for:    lynx
# http://www.crl.com/~subir/lynx.html
# http://www.wfbr.edu/dir/lynx/
# Version required:     2.7.1f
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.41 1997/07/17 07:00:32 asami Exp $
#

DISTNAME=       lynx2-7-1
PKGNAME=        lynx+fotemods-2.7.1f
CATEGORIES=	www
MASTER_SITES=   http://www.slcc.edu/lynx/fote/patches/ \
		http://www.slcc.edu/lynx/fote/
DISTFILES=      lynx2-7-1.zip fotemods.zip

MAINTAINER=	ache@FreeBSD.ORG

BUILD_DEPENDS=  unzip:${PORTSDIR}/archivers/unzip

EXTRACT_CMD=    unzip
EXTRACT_ARGS=   -q -u -o
ALL_TARGET=     freebsd-ncurses
MAN1=		lynx.1

.include <bsd.port.mk>
