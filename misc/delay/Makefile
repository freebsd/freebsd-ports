# New ports collection makefile for:   misc/delay
# Version required:    delay-1.3
# Date created:        03 Mar 1999
# Whom:                gmarco@giovannelli.it
#
# $FreeBSD$
#

DISTNAME=	delay-1.3
CATEGORIES=	misc
MASTER_SITES=	http://onegeek.org/~tom/software/delay/dl/

MAINTAINER=	gmarco@giovannelli.it

HAS_CONFIGURE=	yes

MAN1=	delay.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/delay ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/delay.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
