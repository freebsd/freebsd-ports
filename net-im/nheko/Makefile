PORTNAME=	nheko
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.0
PORTREVISION=	1
CATEGORIES=	net-im

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Matrix IM client based on Qt technologies
WWW=		https://nheko.im/nheko-reborn/nheko/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	nlohmann-json>=3:devel/nlohmann-json \
		asciidoc>=10:textproc/asciidoc
# All those boost-libs are pulled in through mtxclient, which
# links to them but stage-qa still complains.
LIB_DEPENDS=	\
		libcmark.so:textproc/cmark \
		libcoeurl.so:ftp/coeurl \
		libkdsingleapplication-qt6.so:devel/kdsingleapplication \
		libfmt.so:devel/libfmt \
		libspdlog.so:devel/spdlog \
		liblmdb.so:databases/lmdb \
		libmatrix_client.so:net-im/mtxclient \
		libolm.so:security/olm \
		libqt6keychain.so:security/qtkeychain@qt6

USES=		cmake compiler:c++20-lang desktop-file-utils \
		localbase:ldflags pkgconfig qt:6 ssl tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	Nheko-Reborn
GH_TUPLE=	hoytech:lmdbxx:029fb681213af3020f5e3a86045445552bd024c5:lmdb/deps/lmdb
USE_QT=		base declarative multimedia \
		svg \
		tools:build translations:build

# There is one external dependency: lmdb++
#  - lmdb++ is a single header file, it just needs to be included
CMAKE_ARGS=	-DLMDBXX_INCLUDE_DIR=${WRKSRC}/deps/lmdb \
		-DCMAKE_INSTALL_MANDIR=share/man
CFLAGS+=	-DSPDLOG_FMT_EXTERNAL=1
LDFLAGS+=	-L${LOCALBASE}/lib -lfmt

PATCH_STRIP=	-p1

OPTIONS_DEFINE=	VOIP
OPTIONS_DEFAULT=

VOIP_DESC=	Enable VOIP calls (experimental)
VOIP_LIB_DEPENDS=	libnice.so:net-im/libnice
VOIP_USES=	gstreamer gettext-runtime xorg gnome
VOIP_USE=	gstreamer=bad,dtls,srtp,webrtc xorg=xcb gnome=glib20
VOIP_CMAKE_BOOL=	VOIP


.include <bsd.port.mk>
