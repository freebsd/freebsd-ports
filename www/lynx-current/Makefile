# New ports collection makefile for:    lynx
# http://sol.slcc.edu/lynx/current/
# Version required:     2.7.1ac
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.49 1997/08/16 00:21:31 ache Exp $
#

DISTNAME=       lynx2.7.1ac-0.51
PKGNAME=        lynx-2.7.1ac-0.51
CATEGORIES=	www
MASTER_SITES=   http://sol.slcc.edu/lynx/current/

MAINTAINER=	ache@FreeBSD.ORG

WRKSRC=         ${WRKDIR}/lynx2-7-1
GNU_CONFIGURE=  YES
CONFIGURE_ARGS= --with-screen=ncurses
MAKE_FLAGS=     libdir=${PREFIX}/etc \
		SITE_DEFS=-DLYNX_CFG_FILE='\\\"${PREFIX}/etc/lynx.cfg\\\"' \
		-f
MAKEFILE=       makefile
MAN1=		lynx.1

.include <bsd.port.mk>
