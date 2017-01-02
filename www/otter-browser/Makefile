# $FreeBSD$

PORTNAME=	otter-browser
PORTVERSION=	0.9.12
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Browser based on Qt 5

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libhunspell-1.5.so:textproc/hunspell

USES=		cmake:outsource compiler:c++11-lib desktop-file-utils
USE_QT5=	concurrent core dbus gui multimedia network printsupport \
		qml script sql sql-sqlite3 webkit widgets xmlpatterns \
		buildtools_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	OtterBrowser

.include <bsd.port.mk>
