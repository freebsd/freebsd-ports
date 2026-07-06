PORTNAME=	seafile-gui
DISTVERSIONPREFIX=	v
DISTVERSION=	9.0.18
PORTREVISION=	1
CATEGORIES=	net-mgmt devel

MAINTAINER=	d.stoye@cms.hu-berlin.de
COMMENT=	Open Source Cloud Storage (Client)
WWW=		https://github.com/haiwen/seafile

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsearpc.so:devel/libsearpc \
		libseafile.so:net-mgmt/seafile-client \
		libsqlite3.so:databases/sqlite3 \
		libjansson.so:devel/jansson \
		libevent.so:devel/libevent \
		libuuid.so:misc/libuuid

USES=		compiler:c++11-lang cmake gnome pkgconfig qt:6 shebangfix ssl
SHEBANG_FILES=	extensions/*.sh scripts/*.sh fsplugin/*.sh \
		scripts/*.py

USE_GITHUB=	yes
GH_ACCOUNT=	haiwen
GH_PROJECT=	seafile-client

USE_GNOME=	glib20
USE_GL= 	gl opengl
USE_QT= 	5compat base declarative positioning \
		webengine webchannel
CMAKE_ARGS=	-DCMAKE_INCLUDE_PATH:PATH=include/glib-2.0 \
		-DOPENSSL_INCLUDE_DIRS=${OPENSSLINC} \
		-DOPENSSL_LIBRARIES="-L${OPENSSLLIB} -lcrypto" \
		-DBUILD_SHIBBOLETH_SUPPORT=ON \
		-DQT_VERSION_MAJOR=6

# Note that per PR 197984, cairo must be built with X11 and XCB options
# otherwise configure fails with "cairo needs x11 enabled" message

.include <bsd.port.mk>
