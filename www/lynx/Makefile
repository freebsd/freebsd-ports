# New ports collection makefile for:    lynx
# Version required:     2.8.1 release 2
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.82 1999/04/14 19:35:43 mharo Exp $
#

DISTNAME=       lynx2.8.1rel.2
PKGNAME=        lynx-2.8.1.2
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
	${INSTALL_DATA} ${WRKSRC}/lynx.cfg ${PREFIX}/etc/lynx.cfg.default

.include <bsd.port.mk>
