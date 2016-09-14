# Created by: Andy Kosela <akosela@andykosela.com>
# $FreeBSD$

PORTNAME=	fortune-mod-epictetus
PORTVERSION=	0.2
DISTVERSIONPREFIX=	v
CATEGORIES=	misc

MAINTAINER=	akosela@andykosela.com
COMMENT=	Quotes from Epictetus

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	fortune_strfile:misc/fortune_strfile
STRFILE=	${LOCALBASE}/bin/fortune_strfile

USE_GITHUB=	yes
GH_ACCOUNT=	akosela

PLIST_FILES=	share/games/fortune/epictetus \
		share/games/fortune/epictetus.dat

do-build:
	(cd ${WRKSRC} && ${STRFILE} epictetus)

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games/fortune
	${INSTALL_DATA} ${WRKSRC}/epictetus* \
		${STAGEDIR}${PREFIX}/share/games/fortune

.include <bsd.port.mk>
