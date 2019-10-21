# $FreeBSD$

PORTNAME=	oksh
DISTVERSION=	6.6
PORTEPOCH=	1
CATEGORIES=	shells
MASTER_SITES=	https://github.com/ibara/oksh/releases/download/oksh-${DISTVERSION}/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Portable OpenBSD Korn shell

LICENSE=	PD

HAS_CONFIGURE=	yes

OPTIONS_DEFINE=		CURSES STATIC
OPTIONS_DEFAULT=	CURSES

CURSES_DESC=	Use ncurses for screen clearing routines

CURSES_USES=			ncurses
CURSES_CONFIGURE_ENABLE=	curses

STATIC_CONFIGURE_ENABLE=	static

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
