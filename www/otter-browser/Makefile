# $FreeBSD$

PORTNAME=	otter-browser
PORTVERSION=	0.9.11
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Browser based on Qt 5

USE_QT5=	concurrent core dbus gui multimedia network printsupport \
		qml script sql sql-sqlite3 webkit widgets xmlpatterns \
		buildtools_build qmake_build
USES=		cmake:outsource compiler:c++11-lib desktop-file-utils

USE_GITHUB=	yes
GH_ACCOUNT=	OtterBrowser

.include <bsd.port.mk>
