# New ports collection makefile for:    lynx
# http://www.nyu.edu/pages/wsn/subir/lynx.html
# http://www.wfbr.edu/dir/lynx/
# Version required:     2.6
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.31 1996/11/18 11:41:29 asami Exp $
#

DISTNAME=       lynx2-6
PKGNAME=        lynx-2.6
CATEGORIES=	www
MASTER_SITES=   ftp://ftp2.cc.ukans.edu/pub/lynx/lynx2-6/ \
		ftp://ftp.more.net/pub/mirrors/lynx/ \
		http://www.mtsu.edu/~ripa0003/
DISTFILES=      ${DISTNAME}.zip 2-6update.zip

#PATCH_SITES=    http://www.nyu.edu/pages/wsn/subir/lynx/patches/
#PATCHFILES=     2-6-patch11.txt

MAINTAINER=	ache@FreeBSD.ORG

BUILD_DEPENDS=  unzip:${PORTSDIR}/archivers/unzip

EXTRACT_CMD=    unzip
EXTRACT_ARGS=   -q -o
ALL_TARGET=     freebsd-ncurses
MAN1=		lynx.1

.include <bsd.port.mk>

# must be after bsd.port.mk

#PATCH_DIST_ARGS+= -d ${WRKSRC}/src
