PORTNAME=	acalc
PORTVERSION=	0.3
CATEGORIES=	math

MAINTAINER=	andrey.nik.ponomarenko@gmail.com
COMMENT=	Simple and pretty Qt5-based expression calculator
WWW=		https://github.com/anpp/acalc

LICENSE=	BSD4CLAUSE

USES=		compiler:c++14-lang qmake qt:5 tar:xz

USE_GITHUB=	yes
GH_ACCOUNT=	anpp

USE_QT=		core gui widgets buildtools:build linguisttools:build qmake:build

WRKSRC_SUBDIR=	aCalc/aCalc

PLIST_FILES=	bin/acalc share/pixmaps/Calculator-50.png

DESKTOP_ENTRIES="acalc" "" "${PREFIX}/share/pixmaps/Calculator-50.png" \
		"${PORTNAME}" "" ""

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/acalc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Icons/Calculator-50.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
