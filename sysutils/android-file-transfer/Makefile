# $FreeBSD$

PORTNAME=	android-file-transfer
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0
PORTREVISION?=	0
CATEGORIES=	sysutils

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Android MTP client with minimalistic UI

LICENSE=	GPLv3+

USE_GITHUB=	yes
GH_ACCOUNT=	whoozle
GH_PROJECT=	${PORTNAME}-linux

USES=		cmake compiler:c++11-lib pkgconfig
CMAKE_ON=	USB_BACKEND_LIBUSB
PLIST_FILES=	"@comment lib/libmtp-ng-static.a"

OPTIONS_DEFINE=	CLI FUSE OPENSSL PYTHON QT5 TAGLIB
OPTIONS_DEFAULT=CLI FUSE OPENSSL PYTHON QT5 TAGLIB
OPTIONS_EXCLUDE?=	QT5 # enslaved until subpackaging

CLI_DESC=	CLI (Command-Line Interface) support
CLI_USES=	readline
CLI_PLIST_FILES=bin/aft-mtp-cli

FUSE_USES=	fuse
FUSE_CMAKE_BOOL=BUILD_FUSE
FUSE_PLIST_FILES=bin/aft-mtp-mount

OPENSSL_USES=		ssl
OPENSSL_CMAKE_BOOL=	BUILD_MTPZ

PYTHON_BUILD_DEPENDS=	pybind11>0:devel/pybind11
PYTHON_USES=		python
PYTHON_CMAKE_BOOL=	BUILD_PYTHON
PYTHON_PLIST_FILES=	%%PYTHON_SITELIBDIR%%/aftl.so

QT5_USES=	qt:5
QT5_USE=	QT=qmake_build,buildtools_build,linguisttools_build,core,gui,network,widgets
QT5_CMAKE_BOOL=	BUILD_QT_UI
QT5_CMAKE_ON=	-DDESIRED_QT_VERSION:STRING=5
QT5_PLIST_FILES=	bin/android-file-transfer \
		share/applications/android-file-transfer.desktop \
		share/icons/hicolor/512x512/apps/android-file-transfer.png \
		share/metainfo/android-file-transfer.appdata.xml

TAGLIB_DESC=		Reading audio metadata via taglib
TAGLIB_LIB_DEPENDS=	libtag.so:audio/taglib
TAGLIB_CMAKE_BOOL=	BUILD_TAGLIB

post-patch:
	@${REINPLACE_CMD} '/set.*AFT_VERSION/s/".*"/"${DISTVERSIONFULL}"/' \
		${WRKSRC}/CMakeLists.txt

post-patch-CLI-off:
	@${REINPLACE_CMD} '/subdirectory(cli)/d' ${WRKSRC}/CMakeLists.txt

post-install-PYTHON-on:
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${INSTALL_LIB} ${BUILD_WRKSRC}/python/aftl.so \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
