# Created by: Doug Barton <dougb@FreeBSD.org>

PORTNAME=	libtorrent-rasterbar
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.6-27
DISTVERSIONSUFFIX=	-g34c75eb5f
PORTEPOCH=	1
CATEGORIES=	net-p2p python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings for libtorrent-rasterbar

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../../COPYING

BROKEN=		fails to build, see https://github.com/arvidn/libtorrent/issues/6890

BUILD_DEPENDS=	b2:devel/boost_build
LIB_DEPENDS=	libtorrent-rasterbar.so:net-p2p/libtorrent-rasterbar \
		${PY_BOOST}

USES=		compiler:c11 iconv localbase:ldflags python:3.6+
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	arvidn
GH_PROJECT=	libtorrent
GH_TUPLE=	arvidn:try_signal:751a7e5:try_signal/../../deps/try_signal \
		arvidn:libsimulator:64fb5b4:libsimulator/../../simulation/libsimulator \
		paullouisageneau:boost-asio-gnutls:a57d4d3:asio/../../deps/asio-gnutls

BINARY_ALIAS=	b2=${FILESDIR}/b2

USE_CXXSTD=	c++17 # prevent boost-related SEGV, see bug#264278
CFLAGS+=	-DTORRENT_DISABLE_LOGGING # undefined symbol: https://github.com/arvidn/libtorrent/issues/3331
LDFLAGS+=	${LOCALBASE}/lib/libboost_python${PYTHON_SUFFIX}.so ${LOCALBASE}/lib/libiconv.so # fails to link libs: https://github.com/arvidn/libtorrent/issues/3330

WRKSRC_SUBDIR=	bindings/python

# ensure python paths are correctly identified
CONFIGURE_ENV=	PYTHON_INCLUDEDIR="${PYTHON_INCLUDEDIR}" \
		PYTHON_VERSION="${PYTHON_VERSION}"

PORTSCOUT=	limit:^1.* # 2.x is WIP and we don't accept it before qBittorrent does

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/libtorrent*.so

.include <bsd.port.mk>
