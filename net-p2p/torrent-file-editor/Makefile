# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	torrent-file-editor
PORTVERSION=	0.3.9
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME}/v${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Qt-based GUI tool for creating and editing .torrent files

LICENSE=	GPLv3

USES=		cmake desktop-file-utils

_QT4_DEPS=	linguisttools_build moc_build qmake_build rcc_build \
		uic_build corelib gui
_QT5_DEPS=	buildtools_build linguisttools_build qmake_build \
		core gui widgets

OPTIONS_DEFINE=	DONATION QT5
OPTIONS_DEFAULT=	DONATION

DONATION_DESC=	Show donation text in the About dialog
QT5_DESC=	Build against Qt 5 instead of Qt 4

DONATION_CMAKE_OFF=	-DDISABLE_DONATION:BOOL=ON

QT5_USE=	QT5=${_QT5_DEPS:ts,}
QT5_USE_OFF=	QT4=${_QT4_DEPS:ts,}
QT5_LIB_DEPENDS_OFF=	libqjson.so:devel/qjson
QT5_CMAKE_ON=	-DQT5_BUILD:BOOL=ON

.include <bsd.port.mk>
