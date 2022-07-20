PORTNAME=	posterazor
PORTVERSION=	1.9.7
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	print graphics

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Cuts an image into pieces which can be printed out as a poster

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang dos2unix gl localbase:ldflags qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	ehaupt
USE_GL=		gl
USE_QT=		core gui printsupport widgets buildtools_build

QMAKE_SOURCE_PATH=	${WRKSRC}/src/posterazor.pro

DESKTOP_ENTRIES=	"PosteRazor" \
			"Make your own poster!" \
			"${PREFIX}/share/pixmaps/posterazor.xpm" \
			"posterazor" \
			"Application;Graphics;" \
			""

PLIST_FILES=	bin/posterazor \
		share/pixmaps/posterazor.xpm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/PosteRazor \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/icons/${PORTNAME}.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
