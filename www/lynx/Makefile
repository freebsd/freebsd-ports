# New ports collection makefile for:    lynx
# http://sol.slcc.edu/lynx/current/
# Version required:     2.7.1ac
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.53 1997/08/22 07:56:50 ache Exp $
#

DISTNAME=       lynx2.7.1ac-0.56
PKGNAME=        lynx-2.7.1ac-0.56
CATEGORIES=	www
MASTER_SITES=   http://sol.slcc.edu/lynx/current/

MAINTAINER=	ache@FreeBSD.ORG

WRKSRC=         ${WRKDIR}/lynx2-7-1
GNU_CONFIGURE=  YES
CONFIGURE_ARGS= --with-screen=ncurses --with-zlib
MAKE_FLAGS=     libdir=${PREFIX}/etc \
		SITE_DEFS=-DLYNX_CFG_FILE='\\\"${PREFIX}/etc/lynx.cfg\\\"' \
		-f
MAKEFILE=       makefile
MAN1=		lynx.1

.include <bsd.port.mk>
