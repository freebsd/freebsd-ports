PORTNAME=	nekobox
DISTVERSION=	5.11.22
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Qt-based GUI proxy utility powered by Sing-box
WWW=		https://github.com/qr243vbi/nekobox

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	thrift:devel/thrift
LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libcpr.so:www/cpr \
		libcurl.so:ftp/curl \
		libleveldb.so:databases/leveldb \
		libsnappy.so:archivers/snappy \
		libthrift.so:devel/thrift-cpp \
		libyaml-cpp.so:devel/yaml-cpp
RUN_DEPENDS=	sing-box:net/sing-box

USES=		cmake compiler:c++20-lang desktop-file-utils gl localbase:ldflags pkgconfig qt:6 xorg
USE_GL=		opengl
USE_QT=		base tools:build
USE_XORG=	ice sm x11 xext

USE_GITHUB=	yes
GH_ACCOUNT=	qr243vbi
GH_PROJECT=	nekobox
GH_TUPLE=	libcpr:cpr:e3edc33:cpr/src/3rdparty/cpr \
		quickjs-ng:quickjs:fd0a021:qjs/src/3rdparty/qjs

CMAKE_ON=	CMAKE_SKIP_INSTALL_RPATH \
		SKIP_UPDATER
CMAKE_OFF=	SKIP_JS_UPDATER \
		BUILD_GO_PARTS

post-patch:
	${CP} ${FILESDIR}/server_freebsd.go ${WRKSRC}/core/server/
	${CP} ${FILESDIR}/dns_manager_freebsd.go ${WRKSRC}/core/server/internal/boxdns/
	${CP} ${FILESDIR}/monitor_freebsd.go ${WRKSRC}/core/server/internal/boxdns/

.include <bsd.port.mk>
