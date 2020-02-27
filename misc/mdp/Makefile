# $FreeBSD$

PORTNAME=	mdp
PORTVERSION=	1.0.15
CATEGORIES=	misc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Command-line based markdown presentation tool

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake ncurses

USE_GITHUB=	yes
GH_ACCOUNT=	visit1985

MAKE_ARGS=	CURSES=${NCURSES_IMPL}

PLIST_FILES=	bin/mdp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mdp ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
