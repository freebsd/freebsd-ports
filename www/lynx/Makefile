# New ports collection makefile for:    lynx
# Version required:     2.7.1
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.73 1997/12/02 00:24:29 jseger Exp $
#

DISTNAME=       lynx2-7-1
PKGNAME=        lynx-2.7.1
CATEGORIES=	www
MASTER_SITES=   http://sol.slcc.edu/lynx/release/
EXTRACT_SUFX=	.zip

MAINTAINER=	jseger@FreeBSD.ORG

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

MAN1=		lynx.1
EXTRACT_CMD=	unzip
EXTRACT_BEFORE_ARGS=	-qq
ALL_TARGET=	freebsd-ncurses

.include <bsd.port.mk>
