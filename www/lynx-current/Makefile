# New ports collection makefile for:    lynx
# http://sol.slcc.edu/lynx/current/
# Version required:     2.8rel.2
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.84 1998/03/11 01:54:20 ache Exp $
#

DISTNAME=       lynx2.8rel.2
PKGNAME=        lynx-2.8rel.2
CATEGORIES=	www
MASTER_SITES=   http://sol.slcc.edu/lynx/current/

MAINTAINER=	ache@FreeBSD.ORG

NO_LATEST_LINK=	YES
WRKSRC=         ${WRKDIR}/lynx2-8
GNU_CONFIGURE=  YES
CONFIGURE_ARGS= --with-screen=ncurses --with-zlib --libdir="${PREFIX}/etc"
MAKEFILE=       makefile
INSTALL_TARGET= install install-help
MAN1=		lynx.1

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/lynx_help

.include <bsd.port.mk>
