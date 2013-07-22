# New ports collection makefile for:   qtresistors
# Date created:                2010-01-10
# Whom:                        Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	qtresistors
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	http://qt-apps.org/CONTENT/content-files/
DISTNAME=	118297-qtResistors-201001102229

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Calculate resistance of resistor by the colors on the resistor

USE_QT4=	gui qmake_build uic_build moc_build

WRKSRC=		${WRKDIR}/qtResistors

PLIST_FILES=	bin/${PORTNAME}

do-configure:
	cd ${WRKSRC} && ${QMAKE} ${QMAKEFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qtResistors ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
