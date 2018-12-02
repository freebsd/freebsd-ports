# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	qtresistors
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	http://qt-apps.org/CONTENT/content-files/
DISTNAME=	118297-qtResistors-201001102229

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Calculate resistance of resistor by the colors on the resistor

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USES=		qmake qt:4
USE_QT=		gui uic_build moc_build

WRKSRC=		${WRKDIR}/qtResistors

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qtResistors ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
