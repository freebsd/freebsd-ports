# Created by: Doug Barton <dougb@FreeBSD.org>
# $FreeBSD$

CATEGORIES=	net-p2p python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Python bindings for libtorrent-rasterbar

LIB_DEPENDS=	libtorrent-rasterbar.so:${PORTSDIR}/net-p2p/libtorrent-rasterbar \
		libboost_python.so:${PORTSDIR}/devel/boost-python-libs

MASTERDIR=	${.CURDIR}/../libtorrent-rasterbar

BUILD_WRKSRC=	${WRKSRC}/bindings/python
INSTALL_WRKSRC=	${BUILD_WRKSRC}

SLAVE_PORT=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	python_libtorrent

PLIST=		${NONEXISTENT}
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/libtorrent.so

OPTIONS_EXCLUDE=	DOCS EXAMPLES

# insure python paths are correctly identified
CONFIGURE_ENV=	PYTHON_INCLUDEDIR="${PYTHON_INCLUDEDIR}" \
		PYTHON_VERSION="${PYTHON_VERSION}"

.include "${MASTERDIR}/Makefile"
