# $FreeBSD$

PORTNAME=	android-file-transfer
DISTVERSIONPREFIX=	v
DISTVERSION=	3.9
PORTREVISION?=	1
CATEGORIES=	sysutils

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Android MTP client with minimalistic UI

LICENSE=	GPLv3+

USE_GITHUB=	yes
GH_ACCOUNT=	whoozle
GH_PROJECT=	${PORTNAME}-linux

USES=		cmake compiler:c++11-lib localbase:ldflags pkgconfig
CMAKE_ON=	USB_BACKEND_LIBUSB
PLIST_FILES=	"@comment lib/libmtp-ng-static.a"

OPTIONS_DEFINE=	CLI FUSE QT5
OPTIONS_DEFAULT=CLI FUSE QT5
OPTIONS_EXCLUDE?=	QT5 # enslaved until subpackaging

CLI_DESC=	CLI (Command-Line Interface) support
CLI_USES=	readline
CLI_PLIST_FILES=bin/aft-mtp-cli

FUSE_USES=	fuse
FUSE_CMAKE_BOOL=BUILD_FUSE
FUSE_PLIST_FILES=bin/aft-mtp-mount

QT5_USES=	qt:5
QT5_USE=	QT=qmake_build,buildtools_build,core,gui,widgets
QT5_CMAKE_BOOL=	BUILD_QT_UI
QT5_CMAKE_ON=	-DDESIRED_QT_VERSION:STRING=5
QT5_PLIST_FILES=	bin/android-file-transfer \
		share/applications/android-file-transfer.desktop \
		share/icons/hicolor/512x512/apps/android-file-transfer.png \
		share/metainfo/android-file-transfer.appdata.xml

post-patch:
	@${REINPLACE_CMD} '/set.*AFT_VERSION/s/".*"/"${DISTVERSIONFULL}"/' \
		${WRKSRC}/CMakeLists.txt

post-patch-CLI-off:
	@${REINPLACE_CMD} '/subdirectory(cli)/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
