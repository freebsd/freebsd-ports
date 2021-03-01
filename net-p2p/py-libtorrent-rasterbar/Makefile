# Created by: Doug Barton <dougb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libtorrent-rasterbar
DISTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	net-p2p python
MASTER_SITES=	https://github.com/arvidn/libtorrent/releases/download/v${DISTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/arvidn/libtorrent/commit/
PATCHFILES=	2e9a8423c8e2d3eba49165bacbae2878e25991cb.patch:-p3 # https://github.com/arvidn/libtorrent/pull/6016/commits

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings for libtorrent-rasterbar

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../../COPYING

BUILD_DEPENDS=	b2:devel/boost_build
#LIB_DEPENDS=	libtorrent-rasterbar.so:net-p2p/libtorrent-rasterbar \
#		${PY_BOOST}
LIB_DEPENDS=	${PY_BOOST} # Python binding rebuilds whole libtorrent: https://github.com/arvidn/libtorrent/issues/6017

USES=		compiler:c11 iconv localbase:ldflags python:3.6+
USE_PYTHON=	distutils autoplist

BINARY_ALIAS=	b2=${FILESDIR}/b2

CFLAGS+=	-DTORRENT_DISABLE_LOGGING # undefined symbol: https://github.com/arvidn/libtorrent/issues/3331
#LDFLAGS+=	${LOCALBASE}/lib/libboost_python${PYTHON_SUFFIX}.so ${LOCALBASE}/lib/libiconv.so # fails to link libs: https://github.com/arvidn/libtorrent/issues/3330

PYDISTUTILS_BUILD_TARGET=	build_ext
PYDISTUTILS_BUILDARGS=		--boost-link=shared # otherwise it uses the static library and fails to build the python object: can't create dynamic relocation R_X86_64_32S against local symbol in readonly segment

WRKSRC_SUBDIR=	bindings/python

# ensure python paths are correctly identified
CONFIGURE_ENV=	PYTHON_INCLUDEDIR="${PYTHON_INCLUDEDIR}" \
		PYTHON_VERSION="${PYTHON_VERSION}" \
		BOOST_ROOT=${LOCALBASE}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/libtorrent*.so

.include <bsd.port.mk>
