# Created by: domi@saargate.de
# $FreeBSD$

PORTNAME=	rand
PORTVERSION=	1.8
CATEGORIES=	textproc
MASTER_SITES=	http://bzflag.bz/~erik/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to display files or streams in random order

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		rand.1
PLIST_FILES=	bin/rand

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/rand ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/rand.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
