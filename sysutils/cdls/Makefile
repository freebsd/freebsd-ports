# Created by: Hans de Hartog
# $FreeBSD$

PORTNAME=	cdls
PORTVERSION=	4.2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://freebsd4ever.xs4all.nl/ ftp://vps337.directvps.nl/

MAINTAINER=	hansdehartog@xs4all.nl
COMMENT=	Curses based file manager for system managers

PLIST_FILES=	bin/cdls

USES=		ncurses

.include <bsd.port.pre.mk>

.if ${NCURSESBASE} == /usr
# no need to use ncurses-config if we use ncurses from the base system
CONFIGURE_ARGS+=	NCURSES_CONFIG=/usr/bin/true
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cdls ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
