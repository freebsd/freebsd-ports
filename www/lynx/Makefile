# New ports collection makefile for:    lynx
# Version required:     2.8.2 release 1
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.84 1999/06/18 21:18:27 mph Exp $
#

DISTNAME=       lynx2.8.2rel.1
PKGNAME=        lynx-2.8.2rel.1
CATEGORIES=	www
MASTER_SITES=   http://sol.slcc.edu/lynx/current/

MAINTAINER=	jseger@FreeBSD.ORG

USE_BZIP2=      YES
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
