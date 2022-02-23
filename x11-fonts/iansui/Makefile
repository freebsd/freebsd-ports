PORTNAME=	iansui
PORTVERSION=	0.940
DISTVERSIONPREFIX=	v
CATEGORIES=	x11-fonts

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Open source Chinese font derived from Klee One (Fontworks)

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts

USE_GITHUB=	yes
GH_ACCOUNT=	ButTaiwan

NO_ARCH=	yes
NO_BUILD=	yes

FONT_FILE=	Iansui${PORTVERSION:C/\.//:C/0+$//}-Regular.ttf

PLIST_FILES=	${FONTSDIR}/${FONT_FILE}

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/${FONT_FILE} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
