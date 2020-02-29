# $FreeBSD$

PORTNAME=	mdp
PORTVERSION=	1.0.15
PORTREVISION=	1
CATEGORIES=	misc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Command-line based markdown presentation tool

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake ncurses

USE_GITHUB=	yes
GH_ACCOUNT=	visit1985

MAKE_ARGS=	CURSES=${NCURSES_IMPL}

PLIST_FILES=	bin/mdp \
		share/man/man1/mdp.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mdp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mdp.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
