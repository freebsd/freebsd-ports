# New ports collection makefile for:    lynx
# http://sol.slcc.edu/lynx/current/
# Version required:     2.7.1ac
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.78 1998/01/22 22:35:27 ache Exp $
#

DISTNAME=       lynx2.7.1ac-0.111
PKGNAME=        lynx-2.7.1ac-0.111
CATEGORIES=	www
MASTER_SITES=   http://sol.slcc.edu/lynx/current/

MAINTAINER=	ache@FreeBSD.ORG

WRKSRC=         ${WRKDIR}/lynx2-7-1
GNU_CONFIGURE=  YES
CONFIGURE_ARGS= --with-screen=ncurses --with-zlib --libdir="${PREFIX}/etc"
MAKEFILE=       makefile
INSTALL_TARGET= install install-help
MAN1=		lynx.1

.include <bsd.port.mk>
