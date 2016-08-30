# Created by: Frederic Culot <frederic@culot.org>
# $FreeBSD$

PORTNAME=	epte
PORTVERSION=	2.0.8
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://www.toddmiller.com/epte/

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Electronic Periodic Table of the Elements

USES=		ncurses
MAKEFILE=	makefile
ALL_TARGET=	${PORTNAME}

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/epte \
		man/man1/epte.1.gz

post-patch:
	@${REINPLACE_CMD} 's|/usr|${PREFIX}|' ${WRKSRC}/epte.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/epte ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/epte.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
