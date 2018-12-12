# $FreeBSD$

PORTNAME=	otter-browser
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.99.3
PORTREVISION=	2
CATEGORIES=	www

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Browser based on Qt 5

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libhunspell-1.6.so:textproc/hunspell

USES=		cmake:outsource compiler:c++11-lib desktop-file-utils qt:5
USE_QT=		concurrent core dbus declarative gui multimedia network printsupport \
		script sql sql-sqlite3 svg widgets xmlpatterns \
		buildtools_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	OtterBrowser

OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	QTWEBENGINE QTWEBKIT
OPTIONS_DEFAULT=	QTWEBENGINE QTWEBKIT

QTWEBENGINE_DESC=	Build QtWebEngine backend
QTWEBKIT_DESC=		Build QtWebKit backend

QTWEBENGINE_USE=	qt=declarative,location,webchannel,webengine
QTWEBENGINE_CMAKE_BOOL=	ENABLE_QTWEBENGINE

QTWEBKIT_USE=		qt=webkit
QTWEBKIT_CMAKE_BOOL=	ENABLE_QTWEBKIT

.include <bsd.port.mk>
