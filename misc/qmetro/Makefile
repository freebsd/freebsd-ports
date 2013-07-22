# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qmetro
PORTVERSION=	0.6.5
CATEGORIES=	misc graphics
MASTER_SITES=	SF/${PORTNAME}/source/

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Map of the transport system for many city subways

LICENSE=	GPLv2

USE_ZIP=	yes
INSTALLS_ICONS=	yes
USE_QT4=	gui xml qmake_build uic_build moc_build multimedia \
		rcc_build
USE_DOS2UNIX=	rc/alarm.pri

do-configure:
	cd ${WRKSRC} && ${QMAKE} ${QMAKEFLAGS} PREFIX=${PREFIX}

.include <bsd.port.mk>
