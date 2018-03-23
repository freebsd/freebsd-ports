# Created by: Rusty Nejdl <rnejdl@ringofsaturn.com>
# $FreeBSD$

PORTNAME=	filelight
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	sysutils kde kde-kde4
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Map of concentric segmented-rings representing file system

CONFLICTS_INSTALL=      ${PORTNAME}

USES=		cmake:outsource kde:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT4=	qmake_build moc_build rcc_build uic_build

.include <bsd.port.mk>
