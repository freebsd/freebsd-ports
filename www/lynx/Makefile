# New ports collection makefile for:    lynx
# http://sol.slcc.edu/lynx/current/
# Version required:     2.7.1ac
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.67 1997/10/10 14:47:21 ache Exp $
#

DISTNAME=       lynx2.7.1ac-0.84
PKGNAME=        lynx-2.7.1ac-0.84
CATEGORIES=	www
MASTER_SITES=   http://sol.slcc.edu/lynx/current/

MAINTAINER=	ache@FreeBSD.ORG

WRKSRC=         ${WRKDIR}/lynx2-7-1
GNU_CONFIGURE=  YES
CONFIGURE_ARGS= --with-screen=ncurses --with-zlib --libdir="${PREFIX}/etc"
MAKEFILE=       makefile
MAN1=		lynx.1

.include <bsd.port.mk>
