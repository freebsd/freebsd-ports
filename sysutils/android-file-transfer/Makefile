# $FreeBSD$

PORTNAME=	android-file-transfer
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0-10
DISTVERSIONSUFFIX=	-g40640fb
CATEGORIES=	sysutils

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Android MTP client with minimalistic UI

LICENSE=	GPLv3+

USE_GITHUB=	yes
GH_ACCOUNT=	whoozle
GH_PROJECT=	${PORTNAME}-linux

USES=		cmake compiler:c++11-lib localbase pkgconfig readline
CMAKE_ARGS=	-DUSB_BACKEND_LIBUSB=on -DBUILD_QT_UI=off
PLIST_FILES=	bin/aft-mtp-cli

OPTIONS_DEFINE=	FUSE
OPTIONS_DEFAULT=FUSE QT5
OPTIONS_RADIO=	GUI
OPTIONS_RADIO_GUI=	QT4 QT5
# XXX http://lists.dragonflybsd.org/pipermail/users/2016-September/313064.html
OPTIONS_EXCLUDE_DragonFly=	FUSE

FUSE_USES=	fuse
FUSE_CMAKE_BOOL=BUILD_FUSE
FUSE_PLIST_FILES=bin/aft-mtp-mount

QT4_USE=	QT4=qmake_build,moc_build,rcc_build,uic_build,corelib,gui
QT4_CMAKE_ON=	-DBUILD_QT_UI=on -DDESIRED_QT_VERSION=4
QT4_PLIST_FILES=${QT5_PLIST_FILES}

QT5_USE=	QT5=qmake_build,buildtools_build,core,gui,widgets
QT5_CMAKE_ON=	-DBUILD_QT_UI=on -DDESIRED_QT_VERSION=5
QT5_PLIST_FILES=bin/android-file-transfer \
		share/applications/android-file-transfer.desktop \
		share/icons/hicolor/128x128/apps/android-file-transfer.png

.if !exists(/usr/libdata/pkgconfig/libusb-1.0.pc)
CONFIGURE_ENV+=	PKG_CONFIG_PATH="${FILESDIR}"
.endif

.include <bsd.port.mk>
