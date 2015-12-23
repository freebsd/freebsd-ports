# Created by: Jason Bacon <jbacon@mcw.edu>
# $FreeBSD$

PORTNAME=	mcweject
PORTVERSION=	1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Removable media eject

LICENSE=	BSD3CLAUSE

SUB_FILES=	pkg-message

CONFLICTS=	eject-[0-9]*

USES=		tar:xz

do-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/eject.allow ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/eject ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/eject.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
