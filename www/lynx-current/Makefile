# New ports collection makefile for:    lynx
# http://sol.slcc.edu/lynx/current/
# Version required:     2.8pre.2
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.81 1998/02/16 03:41:41 ache Exp $
#

DISTNAME=       lynx2.8pre.2
PKGNAME=        lynx-2.8pre.2
CATEGORIES=	www
MASTER_SITES=   http://sol.slcc.edu/lynx/current/

MAINTAINER=	ache@FreeBSD.ORG

WRKSRC=         ${WRKDIR}/lynx2-8
GNU_CONFIGURE=  YES
CONFIGURE_ARGS= --with-screen=ncurses --with-zlib --libdir="${PREFIX}/etc"
MAKEFILE=       makefile
INSTALL_TARGET= install install-help
MAN1=		lynx.1

.include <bsd.port.mk>
