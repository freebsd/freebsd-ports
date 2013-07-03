# $FreeBSD$

PORTNAME=	entr
PORTVERSION=	2.1
CATEGORIES=	sysutils
MASTER_SITES=	http://entrproject.org/code/

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	Runs arbitrary commands when files change

WRKSRC=	${WRKDIR}/eradman-entr-b621ace9ecba/

PLIST_FILES=	bin/entr
MAN1=	entr.1

do-build:
	cd ${WRKSRC} && ${MAKE} -f Makefile.bsd

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} entr ${PREFIX}/bin/
	cd ${WRKSRC} && ${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
