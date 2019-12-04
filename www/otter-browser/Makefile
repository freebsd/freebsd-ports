# $FreeBSD$

PORTNAME=	otter-browser
DISTVERSIONPREFIX=	v
# Latest upstream release is 1.0.01, this is "after 1.0.01 but before
# whatever comes next".
# DISTVERSION=	1.0.01
PORTVERSION=	1.0.01.1
CATEGORIES=	www

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Browser based on Qt 5

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell

USES=		cmake compiler:c++11-lib desktop-file-utils qt:5
USE_QT=		concurrent core dbus declarative gui multimedia network printsupport \
		script sql sql-sqlite3 svg widgets xmlpatterns \
		buildtools_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	OtterBrowser
GH_TAGNAME=	22de58d

OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	QTWEBENGINE QTWEBKIT
OPTIONS_DEFAULT=	QTWEBKIT
OPTIONS_DEFAULT_amd64=	QTWEBENGINE
OPTIONS_DEFAULT_i386=	QTWEBENGINE
OPTIONS_DEFAULT_powerpc64=	${OPTIONS_DEFAULT_powerpc64_${OSREL:R}}
OPTIONS_DEFAULT_powerpc64_13=	QTWEBENGINE

QTWEBENGINE_DESC=	Build QtWebEngine backend
QTWEBKIT_DESC=		Build QtWebKit backend

QTWEBENGINE_USE=	qt=declarative,location,webchannel,webengine
QTWEBENGINE_CMAKE_BOOL=	ENABLE_QTWEBENGINE

QTWEBKIT_USE=		qt=webkit
QTWEBKIT_CMAKE_BOOL=	ENABLE_QTWEBKIT

.include <bsd.port.mk>
