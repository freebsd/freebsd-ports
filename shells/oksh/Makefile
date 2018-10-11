# $FreeBSD$

PORTNAME=	oksh
DISTVERSION=	20181009
CATEGORIES=	shells
MASTER_SITES=	https://mirrors.nycbug.org/pub/distfiles/

MAINTAINER=	bcallah@openbsd.org
COMMENT=	Portable OpenBSD Korn shell

LICENSE=	PD

OPTIONS_DEFINE=		CURSES STATIC
OPTIONS_DEFAULT=	CURSES

CURSES_DESC=	Use ncurses for screen clearing routines
CURSES_USES=	ncurses

HAS_CONFIGURE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSTATIC}
CONFIGURE_ARGS+=	--enable-static
.endif

.if ${PORT_OPTIONS:MCURSES}
CONFIGURE_ARGS+=	--enable-curses
.else
CONFIGURE_ARGS+=	--disable-curses
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
