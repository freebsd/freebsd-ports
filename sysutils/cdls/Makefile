# Created by: Hans de Hartog <hans@dehartog.nl>
# $FreeBSD$

PORTNAME=	cdls
PORTVERSION=	4.2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://zml12.dyndns.org/ \
		ftp://vps337.directvps.nl/

MAINTAINER=	hans@dehartog.nl
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
