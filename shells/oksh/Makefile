# $FreeBSD$

PORTNAME=	oksh
DISTVERSION=	20181009
CATEGORIES=	shells
MASTER_SITES=	https://mirrors.nycbug.org/pub/distfiles/

MAINTAINER=	bcallah@openbsd.org
COMMENT=	Portable OpenBSD Korn shell

LICENSE=	PD

HAS_CONFIGURE=	yes

OPTIONS_DEFINE=		CURSES STATIC
OPTIONS_DEFAULT=	CURSES

CURSES_DESC=	Use ncurses for screen clearing routines

CURSES_CONFIGURE_ENABLE=	curses
CURSES_USES=			ncurses

STATIC_CONFIGURE_ENABLE=	static

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
