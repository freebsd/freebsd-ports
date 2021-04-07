PORTNAME=	symbola
PORTVERSION=	12
CATEGORIES=	x11-fonts
MASTER_SITES=	http://users.teilar.gr/~g1951d/
DISTNAME=	Symbola
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	elizabeth@interlinked.me
COMMENT=	Basic Latin, Greek, Cyrillic and many Symbol blocks of Unicode

LICENSE=	PD
LICENSE_FILE=	${FILESDIR}/COPYING

USES=		fonts zip

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	${FONTSDIR}/Symbola.ttf	\
		${FONTSDIR}/Symbola_Hinted.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
