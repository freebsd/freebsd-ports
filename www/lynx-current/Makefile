# New ports collection makefile for:    lynx
# http://sol.slcc.edu/lynx/current/
# Version required:     2.8.1dev.X
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.85 1998/03/21 12:54:43 asami Exp $
#

DISTNAME=       lynx2.8.1dev.4
PKGNAME=        lynx-2.8.1dev.4
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
	chown ${SHAREOWN}:${SHAREGRP} ${PREFIX}/etc/lynx.cfg

.include <bsd.port.mk>
