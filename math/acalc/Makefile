# $FreeBSD$

PORTNAME=	acalc
PORTVERSION=	0.3
CATEGORIES=	math

MAINTAINER=	andrey.nik.ponomarenko@gmail.com
COMMENT=	Simple and pretty Qt5-based expression calculator

LICENSE=	BSD4CLAUSE

BROKEN_FreeBSD_12_powerpc64=	fails to compile: settings.cpp:8:136: error: no matching function for call to 'Setting::Setting(<brace-enclosed initializer list>)'

USES=		compiler:c++14-lang qmake qt:5 tar:xz

USE_GITHUB=	yes
GH_ACCOUNT=	anpp

USE_QT=		core gui widgets buildtools_build linguisttools_build qmake_build

WRKSRC_SUBDIR=	aCalc/aCalc

PLIST_FILES=	bin/acalc share/pixmaps/Calculator-50.png

DESKTOP_ENTRIES="acalc" "" "${PREFIX}/share/pixmaps/Calculator-50.png" \
		"${PORTNAME}" "" ""

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/acalc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Icons/Calculator-50.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
