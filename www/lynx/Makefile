# New ports collection makefile for:    lynx
# Version required:     2.8
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.80 1998/10/31 15:36:18 jseger Exp $
#

DISTNAME=       lynx2.8.1rel.1
PKGNAME=        lynx-2.8.1.1
CATEGORIES=	www
MASTER_SITES=   http://sol.slcc.edu/lynx/current/

MAINTAINER=	jseger@FreeBSD.ORG

GNU_CONFIGURE=  YES
CONFIGURE_ARGS= --with-screen=ncurses --with-zlib --libdir="${PREFIX}/etc" \
		--enable-nsl-fork
MAKEFILE=       makefile
INSTALL_TARGET= install install-help
MAN1=		lynx.1

WRKSRC=		${WRKDIR}/lynx2-8-1

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/lynx_help
	chown ${SHAREOWN}:${SHAREGRP} ${PREFIX}/etc/lynx.cfg

.include <bsd.port.mk>
