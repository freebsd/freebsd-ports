PORTNAME=	fortune-mod-epictetus
PORTVERSION=	0.2
DISTVERSIONPREFIX=	v
CATEGORIES=	misc

MAINTAINER=	akosela@andykosela.com
COMMENT=	Quotes from Epictetus

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	akosela

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
