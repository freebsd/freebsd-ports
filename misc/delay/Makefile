# New ports collection makefile for:   misc/delay
# Date created:        03 Mar 1999
# Whom:                gmarco@giovannelli.it
#
# $FreeBSD$
#

PORTNAME=	delay
PORTVERSION=	1.5
CATEGORIES=	misc
MASTER_SITES=	http://onegeek.org/~tom/software/delay/dl/

MAINTAINER=	gmarco@giovannelli.it
COMMENT=	A delay program with feedback to the user

GNU_CONFIGURE=	yes

MAN1=		delay.1
PLIST_FILES=	bin/delay

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/delay ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/delay.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
