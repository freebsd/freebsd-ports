PORTNAME=	android-file-transfer
DISTVERSIONPREFIX=	v
DISTVERSION=	4.5
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	tiago.gasiba@gmail.com
COMMENT=	Android MTP client with minimalistic UI
WWW=		https://github.com/whoozle/android-file-transfer-linux

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lib pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	whoozle
GH_PROJECT=	${PORTNAME}-linux

CMAKE_ON=	USB_BACKEND_LIBUSB
CMAKE_OFF=	BUILD_PYTHON

PORTSCOUT=	skipv:continuous

PLIST_FILES=	"@comment lib/libmtp-ng-static.a"

OPTIONS_DEFINE=		CLI FUSE OPENSSL QT5 TAGLIB
OPTIONS_DEFAULT=	CLI OPENSSL TAGLIB
OPTIONS_EXCLUDE?=	QT5 # enslaved until subpackaging

CLI_DESC=		CLI (Command-Line Interface) support
TAGLIB_DESC=		Reading audio metadata via taglib
CLI_PLIST_FILES=	bin/aft-mtp-cli

FUSE_USES=		fuse:3
FUSE_CMAKE_BOOL=	BUILD_FUSE
FUSE_PLIST_FILES=	bin/aft-mtp-mount

OPENSSL_USES=		ssl
OPENSSL_CMAKE_BOOL=	BUILD_MTPZ

QT5_USES=		qt:5
QT5_USE=		QT=core,gui,network,widgets,buildtools:build,linguisttools:build,qmake:build
QT5_CMAKE_BOOL=		BUILD_QT_UI
QT5_CMAKE_ON=		-DDESIRED_QT_VERSION:STRING=5
QT5_PLIST_FILES=	bin/android-file-transfer \
			share/applications/android-file-transfer.desktop \
			share/icons/hicolor/512x512/apps/android-file-transfer.png \
			share/metainfo/android-file-transfer.appdata.xml

TAGLIB_LIB_DEPENDS=	libtag.so:audio/taglib
TAGLIB_CMAKE_BOOL=	BUILD_TAGLIB

post-patch:
	@${REINPLACE_CMD} '/set.*AFT_VERSION/s/".*"/"${DISTVERSIONFULL}"/' \
		${WRKSRC}/CMakeLists.txt

post-patch-CLI-off:
	@${REINPLACE_CMD} '/subdirectory(cli)/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
