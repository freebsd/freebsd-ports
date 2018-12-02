# Created by: Stas Timokhin <stast@bsdportal.ru>
# $FreeBSD$

PORTNAME=	eiskaltdcpp
PORTREVISION=	9
CATEGORIES=	net-p2p
PKGNAMESUFFIX=	-qt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	EiskaltDC++ Direct Connect client Qt GUI

LICENSE=	GPLv3

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

RUN_DEPENDS=	eiskaltdcpp-data>=0:net-p2p/eiskaltdcpp-data
LIB_DEPENDS=	libeiskaltdcpp.so:net-p2p/eiskaltdcpp-lib

MASTERDIR=	${.CURDIR}/../eiskaltdcpp-lib

USES=		cmake gettext compiler:c++11-lib desktop-file-utils qt:4 ssl
USE_QT=		gui xml network qmake_build uic_build \
		moc_build rcc_build linguisttools_build

OPTIONS_DEFINE=	ASPELL FREE_SPACE DBUS_NOTIFY QTSCRIPT QML SQLITE
OPTIONS_DEFAULT=	FREE_SPACE DBUS_NOTIFY
OPTIONS_SUB=	yes
FREE_SPACE_DESC=	Free space bar in status panel
DBUS_NOTIFY_DESC=	DBus notification support
QTSCRIPT_DESC=		QtScript support
QML_DESC=		Qt Declarative ui support

CMAKE_ARGS+=	-DUSE_QT:BOOL=ON
CMAKE_ARGS+=	-DUSE_GTK:BOOL=OFF
CMAKE_ARGS+=	-DCREATE_MO:BOOL=OFF
CMAKE_ARGS+=	-DINSTALL_DATA:BOOL=OFF

BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}${PKGNAMESUFFIX}
INSTALL_WRKSRC=	${WRKSRC}/${PORTNAME}${PKGNAMESUFFIX}

ASPELL_LIB_DEPENDS=	libaspell.so:textproc/aspell
ASPELL_CMAKE_BOOL=	USE_ASPELL

FREE_SPACE_CMAKE_BOOL=	FREE_SPACE_BAR_C

DBUS_NOTIFY_USE=	QT=dbus
DBUS_NOTIFY_CMAKE_BOOL=	DBUS_NOTIFY

QTSCRIPT_USE=		QT=script
QTSCRIPT_RUN_DEPENDS=	${LOCALBASE}/lib/qt4/plugins/script/libqtscript_core.so:devel/qtscriptgenerator
QTSCRIPT_CMAKE_BOOL=	USE_JS

QML_USE=		QT=declarative
QML_CMAKE_BOOL=		USE_QT_QML

SQLITE_USE=		QT=sql-sqlite3
SQLITE_CMAKE_BOOL=	USE_QT_SQLITE

.include "${MASTERDIR}/Makefile"
