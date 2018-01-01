# $FreeBSD$

PORTNAME=	android-file-transfer
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2
PORTREVISION?=	2
CATEGORIES=	sysutils

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Android MTP client with minimalistic UI

LICENSE=	GPLv3+

USE_GITHUB=	yes
GH_ACCOUNT=	whoozle
GH_PROJECT=	${PORTNAME}-linux

USES=		cmake compiler:c++11-lib localbase:ldflags pkgconfig
CMAKE_ON=	USB_BACKEND_LIBUSB

OPTIONS_DEFAULT=CLI FUSE
OPTIONS_MULTI=	COMP
OPTIONS_MULTI_COMP=	CLI FUSE
OPTIONS_RADIO=	GUI
OPTIONS_RADIO_GUI=	QT QT4 QT5
OPTIONS_SLAVE:=		${OPTIONS_SLAVE} ${OPTIONS_SLAVE:MQT*:C/.+/QT/} # XXX ports/202701
OPTIONS_EXCLUDE:=	${OPTIONS_EXCLUDE} ${OPTIONS_RADIO_GUI}
# XXX http://lists.dragonflybsd.org/pipermail/users/2016-September/313064.html
OPTIONS_EXCLUDE_DragonFly=	FUSE

COMP_DESC=	Components

CLI_DESC=	CLI (Command-Line Interface) support
CLI_USES=	readline
CLI_PLIST_FILES=bin/aft-mtp-cli

FUSE_USES=	fuse
FUSE_CMAKE_BOOL=BUILD_FUSE
FUSE_PLIST_FILES=bin/aft-mtp-mount

QT_CMAKE_BOOL=	BUILD_QT_UI
QT_PLIST_FILES=	bin/android-file-transfer \
		share/applications/android-file-transfer.desktop \
		share/icons/hicolor/128x128/apps/android-file-transfer.png

QT4_USE=	QT4=qmake_build,moc_build,rcc_build,uic_build,corelib,gui
QT4_CMAKE_ON=	-DDESIRED_QT_VERSION:STRING=4
QT4_IMPLIES=	QT

QT5_USE=	QT5=qmake_build,buildtools_build,core,gui,widgets
QT5_CMAKE_ON=	-DDESIRED_QT_VERSION:STRING=5
QT5_IMPLIES=	QT

post-patch:
	@${REINPLACE_CMD} '/set.*AFT_VERSION/s/".*"/"${GH_TAGNAME}"/' \
		${WRKSRC}/CMakeLists.txt

post-patch-CLI-off:
	@${REINPLACE_CMD} '/subdirectory(cli)/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
