# New ports collection makefile for:	 asWedit
# Version required:	4.0
# Date created:		25 June 1997
# Whom:			brett@peloton.physics.montana.edu
#
# $Id: Makefile,v 1.1.1.1 1997/07/10 06:27:38 tg Exp $
#

DISTNAME=	asWedit-4.0-i386.linux
PKGNAME=	asWedit-4.0
CATEGORIES=	editors www
MASTER_SITES=	http://www.advasoft.com/asWedit/ \
		ftp://sunsite.doc.ic.ac.uk/packages/www/asWedit/ \
		ftp://sunsite.auc.dk/pub/infosystems/www/asWedit/ \
		ftp://sunsite.icm.edu.pl/pub/www/asWedit/

MAINTAINER=	brett@peloton.physics.montana.edu

RUN_DEPENDS=    /compat/linux/lib/libc.so.5:${PORTSDIR}/emulators/linux_lib

RESTRICTED=     "Commercial software"
NO_BUILD=	yes
NO_PACKAGE=	${RESTRICTED}
WRKSRC=         ${WRKDIR}/asWedit-4.0

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/asWedit ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/asWedit.hlp ${PREFIX}/lib
	@${MKDIR} ${PREFIX}/share/doc/asWedit
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/asWedit

post-install:
	@${ECHO_MSG} "Be sure to read the license agreement in"
	@${ECHO_MSG} "${PREFIX}/share/doc/asWedit/LICENSE."

.include <bsd.port.mk>
