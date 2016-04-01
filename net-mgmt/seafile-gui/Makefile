# $FreeBSD$

PORTNAME=	seafile-gui
PORTVERSION=	4.1.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt

MAINTAINER=	ultima1252@gmail.com
COMMENT=	Seafile desktop client

LICENSE=	APACHE20

LIB_DEPENDS+=	libglib-2.0.so:devel/glib20 \
		libsearpc.so:devel/libsearpc \
		libseafile.so:net-mgmt/seafile \
		libsqlite3.so:databases/sqlite3 \
		libccnet.so:net-mgmt/ccnet \
		libjansson.so:devel/jansson

USE_GITHUB=	yes
GH_ACCOUNT=	haiwen
GH_PROJECT=	seafile-client

USES=		cmake pkgconfig
USE_QT4=	corelib dbus gui network \
		qmake_build moc_build rcc_build uic_build \
		linguist_build
USE_OPENSSL=	yes
INSTALLS_ICONS=	yes
LRELEASE=	${PREFIX}/bin/lrelease-qt4
CMAKE_ARGS+=	-DCMAKE_INCLUDE_PATH:PATH=include/glib-2.0 \
		-DOPENSSL_INCLUDE_DIRS=${OPENSSLINC} \
		-DOPENSSL_LIBRARIES="-L${OPENSSLLIB} -lcrypto"

CMAKE_BUILD_TYPE=	Release

# Note that per PR 197984, cairo must be built with X11 and XCB options
# otherwise configure fails with "cairo needs x11 enabled" message

.include <bsd.port.mk>
