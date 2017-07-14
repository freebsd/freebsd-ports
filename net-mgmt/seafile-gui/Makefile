# $FreeBSD$

PORTNAME=	seafile-gui
PORTVERSION=	${SEAFILE_CLIENT_VER}
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt devel

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Open Source Cloud Storage (Client)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsearpc.so:devel/libsearpc \
		libseafile.so:net-mgmt/seafile-client \
		libsqlite3.so:databases/sqlite3 \
		libccnet.so:net-mgmt/ccnet-client \
		libjansson.so:devel/jansson \
		libevent.so:devel/libevent \
		libuuid.so:misc/e2fsprogs-libuuid

USE_GITHUB=	yes
GH_ACCOUNT=	haiwen
GH_PROJECT=	seafile-client

USES=		compiler:c++11-lang cmake gettext pkgconfig shebangfix ssl
SHEBANG_FILES=	extensions/*.sh scripts/*.sh fsplugin/*.sh \
		scripts/*.py
USE_GNOME=	glib20
USE_QT5=	core dbus gui network testlib widgets \
		qmake_build buildtools_build linguisttools_build
INSTALLS_ICONS=	yes
CMAKE_ARGS+=	-DCMAKE_INCLUDE_PATH:PATH=include/glib-2.0 \
		-DOPENSSL_INCLUDE_DIRS=${OPENSSLINC} \
		-DOPENSSL_LIBRARIES="-L${OPENSSLLIB} -lcrypto"

OPTIONS_DEFINE=		DEBUG

# Note that per PR 197984, cairo must be built with X11 and XCB options
# otherwise configure fails with "cairo needs x11 enabled" message

.include "${.CURDIR}/../seafile-client/Makefile.include"

.include <bsd.port.mk>
