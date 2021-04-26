PORTNAME=	nheko
DISTVERSIONPREFIX=v
DISTVERSION=	0.8.2
CATEGORIES=	net-im

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Matrix IM client based on Qt technologies

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	nlohmann-json>=3:devel/nlohmann-json
# All those boost-libs are pulled in through mtxclient, which
# links to them but stage-qa still complains.
LIB_DEPENDS=	\
		libboost_chrono.so:devel/boost-libs \
		libboost_date_time.so:devel/boost-libs \
		libboost_iostreams.so:devel/boost-libs \
		libboost_regex.so:devel/boost-libs \
		libboost_system.so:devel/boost-libs \
		libboost_thread.so:devel/boost-libs \
		libcmark.so:textproc/cmark \
		libfmt.so:devel/libfmt \
		liblmdb.so:databases/lmdb \
		libmatrix_client.so:net-im/mtxclient \
		libolm.so:security/olm \
		libqt5keychain.so:security/qtkeychain \
		libspdlog.so:devel/spdlog

USES=		cmake compiler:c++17-lang pkgconfig \
		localbase:ldflags qt:5 ssl tar:xz
USE_QT=		concurrent core dbus declarative gui multimedia network \
		quickcontrols2 svg widgets \
		buildtools_build linguist_build qmake_build

# There is one external dependencie: lmdb++
#  - lmdb++ is a single header file, it just needs to be included
CMAKE_ARGS=	-DLMDBXX_INCLUDE_DIR=${WRKSRC}/deps/lmdb
CFLAGS+=	-DSPDLOG_FMT_EXTERNAL=1
LDFLAGS+=	-L${LOCALBASE}/lib -lfmt

USE_GITHUB=	yes
GH_ACCOUNT=	Nheko-Reborn
GH_TUPLE=	hoytech:lmdbxx:029fb681213af3020f5e3a86045445552bd024c5:lmdb/deps/lmdb

.include <bsd.port.mk>
