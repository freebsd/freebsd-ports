# $FreeBSD$

PORTNAME=	acalc
PORTVERSION=	0.21
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	math

MAINTAINER=	andrey.nik.ponomarenko@gmail.com
COMMENT=	Simple and pretty Qt4-based expression calculator

LICENSE=	BSD4CLAUSE

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USE_GITHUB=	yes
GH_ACCOUNT=	anpp

USES=		qmake qt:4
USE_QT=		corelib gui moc_build rcc_build uic_build
WRKSRC_SUBDIR=	aCalc/aCalc

PLIST_FILES=	bin/acalc share/pixmaps/Calculator-50.png

DESKTOP_ENTRIES="acalc" "" "${PREFIX}/share/pixmaps/Calculator-50.png" \
		"${PORTNAME}" "" ""

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/acalc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Icons/Calculator-50.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
