# New ports collection makefile for:    lynx
# http://sol.slcc.edu/lynx/current/
# Version required:     2.7.1ac
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.41 1997/07/17 07:00:32 asami Exp $
#

DISTNAME=       lynx2.7.1ac-0.44
PKGNAME=        lynx-2.7.1ac-0.44
CATEGORIES=	www
MASTER_SITES=   http://sol.slcc.edu/lynx/current/
WRKSRC=         ${WRKDIR}/lynx2-7-1
GNU_CONFIGURE=  YES
CONFIGURE_ARGS= --with-screen=ncurses
MAKE_FLAGS=     libdir=${PREFIX}/etc \
		SITE_DEFS=-DLYNX_CFG_FILE='\\\"${PREFIX}/etc/lynx.cfg\\\"' \
		-f
MAKEFILE=       makefile

MAINTAINER=	ache@FreeBSD.ORG

ALL_TARGET=     lynx
MAN1=		lynx.1

.include <bsd.port.mk>
