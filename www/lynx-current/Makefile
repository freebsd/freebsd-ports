# New ports collection makefile for:    lynx
# Version required:     2.8.3*
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.100 1999/08/02 03:06:58 ache Exp $
#

DISTNAME=       lynx2.8.3dev.5
PKGNAME=        lynx-2.8.3dev.5
CATEGORIES=	www
MASTER_SITES=   http://sol.slcc.edu/lynx/current/

MAINTAINER=	ache@FreeBSD.ORG

USE_BZIP2=      YES
NO_LATEST_LINK=	YES
WRKSRC=         ${WRKDIR}/lynx2-8-3
GNU_CONFIGURE=  YES
CONFIGURE_ARGS= --with-screen=ncurses --with-zlib --libdir="${L_LIB}" \
		--enable-nsl-fork --enable-persistent-cookies
MAKE_FLAGS=     helpdir=${L_HELP} docdir=${L_DOC} -f
MAKEFILE=       makefile
INSTALL_TARGET= install-full
MAN1=		lynx.1

L_LIB=          ${PREFIX}/etc
L_DOC=          ${PREFIX}/share/doc/lynx
L_HELP=         ${PREFIX}/share/lynx_help

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} ${L_DOC}
	chown -R ${SHAREOWN}:${SHAREGRP} ${L_HELP}
	chown ${SHAREOWN}:${SHAREGRP} ${L_LIB}/lynx.cfg

.include <bsd.port.mk>
