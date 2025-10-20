PORTNAME=	libtorrent-rasterbar
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.20
PORTREVISION=	4
PORTEPOCH=	2
CATEGORIES=	net-p2p python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings for libtorrent-rasterbar
WWW=		https://libtorrent.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../../COPYING

BUILD_DEPENDS=	b2:devel/boost_build
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libtorrent-rasterbar.so:net-p2p/libtorrent-rasterbar \
		${PY_BOOST}

USES=		compiler:c11 iconv localbase:ldflags python
USE_GITHUB=	yes
GH_ACCOUNT=	arvidn
GH_PROJECT=	libtorrent
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	libtorrent
PYDISTUTILS_BUILD_TARGET=	build_ext --b2-args="fpic=on libtorrent-link=shared boost-link=shared"
PYDISTUTILS_INSTALL_TARGET=	build_ext --b2-args="fpic=on libtorrent-link=shared boost-link=shared" install

BINARY_ALIAS=	b2=${FILESDIR}/b2

CFLAGS+=	-DTORRENT_DISABLE_LOGGING # undefined symbol: https://github.com/arvidn/libtorrent/issues/3331
LDFLAGS+=	${LOCALBASE}/lib/libboost_python${PYTHON_SUFFIX}.so ${LOCALBASE}/lib/libiconv.so # fails to link libs: https://github.com/arvidn/libtorrent/issues/3330

WRKSRC_SUBDIR=	bindings/python

# ensure python paths are correctly identified
CONFIGURE_ENV=	PYTHON_INCLUDEDIR="${PYTHON_INCLUDEDIR}" \
		PYTHON_VERSION="${PYTHON_VERSION}"

PORTSCOUT=	limit:^1.* # 2.x is WIP and we don't accept it before qBittorrent does

PLIST_FILES+=	${PYTHON_SITELIBDIR}/${PYDISTUTILS_PKGNAME}/__init__${PYTHON_TAG}.so \
		${PYTHON_SITELIBDIR}/libtorrent-_${DISTVERSION}_-py${PYTHON_VER}.egg-info/PKG-INFO \
		${PYTHON_SITELIBDIR}/libtorrent-_${DISTVERSION}_-py${PYTHON_VER}.egg-info/SOURCES.txt \
		${PYTHON_SITELIBDIR}/libtorrent-_${DISTVERSION}_-py${PYTHON_VER}.egg-info/dependency_links.txt \
		${PYTHON_SITELIBDIR}/libtorrent-_${DISTVERSION}_-py${PYTHON_VER}.egg-info/top_level.txt

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PYDISTUTILS_PKGNAME}/__init__${PYTHON_TAG}.so

.include <bsd.port.mk>
