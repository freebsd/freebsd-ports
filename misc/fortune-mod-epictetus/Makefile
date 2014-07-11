# Created by: Andy Kosela <akosela@andykosela.com>
# $FreeBSD$

PORTNAME=	fortune-mod-epictetus
PORTVERSION=	0.1
CATEGORIES=	misc
MASTER_SITES=	http://github.com/akosela/fortune-mod-epictetus/releases/download/v0.1/

MAINTAINER=	akosela@andykosela.com
COMMENT=	Quotes from Epictetus

USES=		tar:bzip2

PLIST_FILES=	share/games/fortune/epictetus \
		share/games/fortune/epictetus.dat
PLIST_DIRSTRY=	share/games/fortune \
		share/games

STRFILE=	/usr/games/strfile

do-build:
	@(cd ${WRKSRC} && ${STRFILE} epictetus)

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/epictetus* ${STAGEDIR}${PREFIX}/share/games/fortune

.include <bsd.port.mk>
