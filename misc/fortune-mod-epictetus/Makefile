# Created by: Andy Kosela <akosela@andykosela.com>
# $FreeBSD$

PORTNAME=	fortune-mod-epictetus
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://github.com/akosela/fortune-mod-epictetus/releases/download/v0.1/

MAINTAINER=	akosela@andykosela.com
COMMENT=	Quotes from Epictetus

USES=		tar:bzip2

PLIST_FILES=	share/games/fortune/epictetus \
		share/games/fortune/epictetus.dat

.if exists(/usr/games/strfile)
STRFILE=	/usr/games/strfile
.elif exists(/usr/bin/strfile)
STRFILE=	/usr/bin/strfile
.else
IGNORE=		needs strfile command. Please install games distribution of base system
.endif

do-build:
	@(cd ${WRKSRC} && ${STRFILE} epictetus)

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games/fortune
	${INSTALL_DATA} ${WRKSRC}/epictetus* ${STAGEDIR}${PREFIX}/share/games/fortune

.include <bsd.port.mk>
