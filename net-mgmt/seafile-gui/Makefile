# $FreeBSD$

PORTNAME=	seafile-gui
PORTVERSION=	6.0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt devel

MAINTAINER=	ultima1252@gmail.com
COMMENT=	Open Source Cloud Storage (Client)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libglib-2.0.so:devel/glib20 \
		libsearpc.so:devel/libsearpc \
		libseafile.so:net-mgmt/seafile-client \
		libsqlite3.so:databases/sqlite3 \
		libccnet.so:net-mgmt/ccnet-client \
		libjansson.so:devel/jansson \
		libevent.so:devel/libevent2 \
		libuuid.so:misc/e2fsprogs-libuuid

USE_GITHUB=	yes
GH_ACCOUNT=	haiwen
GH_PROJECT=	seafile-client

USES=		compiler:c++11-lang cmake gettext pkgconfig shebangfix
SHEBANG_FILES=	extensions/*.sh scripts/*.sh fsplugin/*.sh \
		scripts/*.py
USE_OPENSSL=	yes
USE_QT5=	core dbus gui network testlib widgets \
		qmake_build buildtools_build linguisttools_build
INSTALLS_ICONS=	yes
CMAKE_ARGS+=	-DCMAKE_INCLUDE_PATH:PATH=include/glib-2.0 \
		-DOPENSSL_INCLUDE_DIRS=${OPENSSLINC} \
		-DOPENSSL_LIBRARIES="-L${OPENSSLLIB} -lcrypto"

OPTIONS_DEFINE=		DEBUG

# Note that per PR 197984, cairo must be built with X11 and XCB options
# otherwise configure fails with "cairo needs x11 enabled" message

.include <bsd.port.mk>
