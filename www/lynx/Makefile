# New ports collection makefile for:    lynx
# Version required:     2.7.2
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.75 1998/01/08 00:30:56 jseger Exp $
#

DISTNAME=       lynx2-7-2
PKGNAME=        lynx-2.7.2
CATEGORIES=	www
MASTER_SITES=   http://sol.slcc.edu/lynx/release/ \
		http://www.slcc.edu/lynx/fote/patches/
DISTFILES=      lynx2-7-2.zip 272fixes.zip

MAINTAINER=	jseger@FreeBSD.ORG

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

MAN1=		lynx.1
EXTRACT_CMD=	unzip
EXTRACT_BEFORE_ARGS=    -qq -o
ALL_TARGET=	freebsd-ncurses

.include <bsd.port.mk>
