# New ports collection makefile for:   webstone
# Version required:    2.0
# Date created:        25 March 1997
# Whom:                Soren Dossing <sauber@netcom.com>
#
# $Id: Makefile,v 1.1.1.1 1997/06/04 05:47:00 asami Exp $
#

DISTNAME=      WebStone-2.0
PKGNAME=       webstone-2.0.1
CATEGORIES=    www benchmarks
MASTER_SITES=  http://www.sgi.com/Products/WebFORCE/WebStone/

MAINTAINER=    sauber@netcom.com

GNU_CONFIGURE= yes
WRKSRC=        ${WRKDIR}/WebStone/src
ALL_TARGET=    install
NO_INSTALL_MANPAGES=yes

post-extract:
	( cd ${WRKSRC}; make clobber )

do-install:
	@${MKDIR} ${PREFIX}/webstone/bin
	@${MKDIR} ${PREFIX}/webstone/conf
	${INSTALL_SCRIPT} ${WRKSRC}/../bin/* ${PREFIX}/webstone/bin
	${INSTALL_DATA} ${WRKSRC}/../conf/* ${PREFIX}/webstone/conf
	${INSTALL_SCRIPT} ${WRKSRC}/../webstone  ${PREFIX}/webstone
.for file in webclient webmaster genrand
	strip ${PREFIX}/webstone/bin/${file}
.endfor

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
