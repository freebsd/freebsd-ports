# ports collection makefile for: Files
# Version required:  2.4
# Date created:      28 Jun 1997
# Whom:              Ruslan Shevchenko <ruslan@shevchenko.kiev.ua>
#
# $Id: Makefile,v 1.2 1998/08/05 09:31:44 asami Exp $
#

DISTNAME=	Files-2.4
PKGNAME=	offix-files-2.4
CATEGORIES=	x11-fm offix
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	desktop_managers/OffiX

MAINTAINER=	ruslan@shevchenko.kiev.ua

RUN_DEPENDS=	execute:${PORTSDIR}/x11/offix-execute \
		editor:${PORTSDIR}/editors/offix-editor

LIB_DEPENDS=	Dnd\\.1\\.:${PORTSDIR}/x11/libdnd \
		Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X_PREFIX=	YES
MAN1=		files.1
MAN3=		regexp.3

post-install:
	@${INSTALL_DATA} ${WRKSRC}/src/Files.ad ${PREFIX}/share/OffiX/

.include <bsd.port.mk>
