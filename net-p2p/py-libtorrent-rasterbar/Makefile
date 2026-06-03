PORTNAME=	libtorrent-rasterbar
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.12
PORTEPOCH=	2
CATEGORIES=	net-p2p python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings for libtorrent-rasterbar
WWW=		https://libtorrent.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	b2:devel/boost_build
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libtorrent-rasterbar.so:net-p2p/libtorrent-rasterbar2 \
		${PY_BOOST}

USES=		compiler:c11 iconv:wchar_t localbase:ldflags python ssl
USE_PYTHON=	distutils autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	arvidn
GH_PROJECT=	libtorrent
GH_TUPLE=	arvidn:try_signal:105cce5:try_signal/deps/try_signal \
		arvidn:libsimulator:66ac6cc:libsimulator/simulation/libsimulator \
		paullouisageneau:boost-asio-gnutls:a57d4d3:asio/deps/asio-gnutls

PYDISTUTILS_PKGNAME=	libtorrent
PYDISTUTILS_BUILD_TARGET=	build_ext --b2-args="fpic=on libtorrent-python-pic=on libtorrent-link=shared boost-link=shared"
PYDISTUTILS_INSTALL_TARGET=	build_ext --b2-args="fpic=on libtorrent-python-pic=on libtorrent-link=shared boost-link=shared" install

BINARY_ALIAS=	b2=${FILESDIR}/b2

CFLAGS+=	-fPIC -DTORRENT_DISABLE_LOGGING # undefined symbol: https://github.com/arvidn/libtorrent/issues/3331
CXXFLAGS+=	-fPIC -DTORRENT_DISABLE_LOGGING # undefined symbol: https://github.com/arvidn/libtorrent/issues/3331
LDFLAGS+=	${LOCALBASE}/lib/libboost_python${PYTHON_SUFFIX}.so ${ICONV_LIB} # fails to link libs: https://github.com/arvidn/libtorrent/issues/3330

BUILD_WRKSRC=	${WRKSRC}/bindings/python
INSTALL_WRKSRC=	${WRKSRC}/bindings/python

# ensure python paths are correctly identified
CONFIGURE_ENV=	PYTHON_INCLUDEDIR="${PYTHON_INCLUDEDIR}" \
		PYTHON_VERSION="${PYTHON_VERSION}"

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/bindings/python

PORTSCOUT=	limit:^1.* # 2.x is WIP and we don't accept it before qBittorrent does

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PYDISTUTILS_PKGNAME}/__init__${PYTHON_TAG}.so

# tests as of 2.0.12: 2 passed in 3.28s

.include <bsd.port.mk>
