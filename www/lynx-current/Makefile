# New ports collection makefile for:    lynx
# http://sol.slcc.edu/lynx/current/
# Version required:     2.8.2*
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.96 1999/02/19 12:34:03 ache Exp $
#

DISTNAME=       lynx2.8.2dev.21
PKGNAME=        lynx-2.8.2dev.21
CATEGORIES=	www
MASTER_SITES=   http://sol.slcc.edu/lynx/current/

MAINTAINER=	ache@FreeBSD.ORG

USE_BZIP2=      YES
NO_LATEST_LINK=	YES
WRKSRC=         ${WRKDIR}/lynx2-8-2
GNU_CONFIGURE=  YES
CONFIGURE_ARGS= --with-screen=ncurses --with-zlib --libdir="${L_LIB}" \
		--enable-nsl-fork --enable-persistent-cookies
MAKE_FLAGS=     helpdir=${L_HELP} -f
MAKEFILE=       makefile
INSTALL_TARGET= install install-help
MAN1=		lynx.1

L_LIB=          ${PREFIX}/etc
L_HELP=         ${PREFIX}/share/lynx_help

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} ${L_HELP}
	chown ${SHAREOWN}:${SHAREGRP} ${L_LIB}/lynx.cfg

.include <bsd.port.mk>
