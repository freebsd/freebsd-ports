# New ports collection makefile for:	 asWedit
# Version required:	3.0
# Date created:		25 June 1997
# Whom:			brett@peloton.physics.montana.edu
#
# $Id$
#

DISTNAME=	asWedit-3.0-i386.linux
PKGNAME=	asWedit-3.0
CATEGORIES=	editors www
MASTER_SITES=	ftp://sunsite.doc.ic.ac.uk/packages/www/asWedit/ \
		ftp://sunsite.auc.dk/pub/infosystems/www/asWedit/ \
		ftp://ftp.ruf.uni-freiburg.de/pub/info/asWedit/ \
		ftp://sunsite.icm.edu.pl/pub/www/asWedit/

MAINTAINER=	brett@peloton.physics.montana.edu

RUN_DEPENDS=    /compat/linux/lib/libc.so.5:${PORTSDIR}/emulators/linux_lib

RESTRICTED=     "Commercial software"
NO_BUILD=	yes
NO_PACKAGE=	${RESTRICTED}
WRKSRC=         ${WRKDIR}/asWedit-3.0

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/asWedit ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/asWedit.hlp ${PREFIX}/lib
	@${MKDIR} ${PREFIX}/share/doc/asWedit
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/asWedit

post-install:
	@${ECHO_MSG} "Be sure to read the license agreement in"
	@${ECHO_MSG} "${PREFIX}/share/doc/asWedit/LICENSE."

.include <bsd.port.mk>
