# New ports collection makefile for:    lynx
# Version required:     2.8
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.78 1998/03/27 05:34:10 ache Exp $
#

DISTNAME=       lynx2-8
PKGNAME=        lynx-2.8
CATEGORIES=	www
MASTER_SITES=   http://sol.slcc.edu/lynx/release/

MAINTAINER=	jseger@FreeBSD.ORG

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

EXTRACT_SUFX=   .zip
EXTRACT_CMD=	unzip
EXTRACT_BEFORE_ARGS=    -qq -o

GNU_CONFIGURE=  YES
CONFIGURE_ARGS= --with-screen=ncurses --with-zlib --libdir="${PREFIX}/etc" \
		--enable-nsl-fork
MAKEFILE=       makefile
INSTALL_TARGET= install install-help
MAN1=		lynx.1

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/lynx_help
	chown ${SHAREOWN}:${SHAREGRP} ${PREFIX}/etc/lynx.cfg

.include <bsd.port.mk>
