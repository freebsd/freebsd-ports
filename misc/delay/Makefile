# New ports collection makefile for:   misc/delay
# Version required:    delay-1.2a
# Date created:        03 Mar 1999
# Whom:                gmarco@scotty.masternet.it
#
# $Id$
#

DISTNAME=  delay-1.2a
CATEGORIES=    misc
MASTER_SITES=  http://onegeek.org/~tom/software/delay/dl/

MAINTAINER=    freebsd@scotty.masternet.it

HAS_CONFIGURE=      yes

MAN1=	delay.1

do-install:

	${INSTALL_PROGRAM} ${WRKSRC}/delay ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/delay.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
