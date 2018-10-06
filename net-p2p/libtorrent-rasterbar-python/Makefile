# Created by: Doug Barton <dougb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libtorrent-rasterbar
DISTVERSION=	1.1.10
CATEGORIES=	net-p2p ipv6 python
MASTER_SITES=	https://github.com/arvidn/libtorrent/releases/download/libtorrent-${PORTVERSION:S/./_/g}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings for libtorrent-rasterbar

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../../COPYING

LIB_DEPENDS=	libtorrent-rasterbar.so:net-p2p/libtorrent-rasterbar \
		${PY_BOOST}

USES=		localbase python:2.7
USE_PYTHON=	distutils autoplist

WRKSRC_SUBDIR=	bindings/python

# ensure python paths are correctly identified
CONFIGURE_ENV=	PYTHON_INCLUDEDIR="${PYTHON_INCLUDEDIR}" \
		PYTHON_VERSION="${PYTHON_VERSION}"

.include <bsd.port.mk>
