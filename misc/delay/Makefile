# Created by: gmarco@giovannelli.it
# $FreeBSD$

PORTNAME=	delay
PORTVERSION=	1.6
CATEGORIES=	misc
MASTER_SITES=	http://onegeek.org/~tom/software/delay/dl/ \
		http://utenti.gufi.org/~gmarco/files/distfiles/ 

MAINTAINER=	gmarco@gufi.org
COMMENT=	A delay program with feedback to the user

GNU_CONFIGURE=	yes

MAN1=		delay.1
PLIST_FILES=	bin/delay

NO_STAGE=	yes
do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/delay ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/delay.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
