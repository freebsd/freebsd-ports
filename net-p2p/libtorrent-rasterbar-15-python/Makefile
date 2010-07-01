# New ports collection makefile for:	libtorrent-rasterbar-15-python
# Date created:		Mon Apr 29 01:53:20 UTC 2010
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
#
# $FreeBSD$

PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Python bindings for libtorrent-rasterbar-15
CATEGORIES=	net-p2p python

CONFLICTS+=	py*-libtorrent-rasterbar-0.14.*

USE_PYTHON=	2.5+

BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}setuptools>=0.6:${PORTSDIR}/devel/py-setuptools
LIB_DEPENDS+=	boost_python.4:${PORTSDIR}/devel/boost-python-libs \
		torrent-rasterbar.6:${PORTSDIR}/net-p2p/libtorrent-rasterbar-15

BUILD_WRKSRC=	${WRKSRC}/bindings/python
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PLIST=		${.CURDIR}/pkg-plist

INSTALLS_EGGINFO=	yes
PYDISTUTILS_EGGINFO=	python_libtorrent-${PORTVERSION}-py${PYTHON_VER}.egg-info

NOPORTDOCS=	yes

slave-post-patch:
	@${REINPLACE_CMD} -E -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/bindings/python/setup.py.in

slave-post-install:
# fix installation permissions
	@${CHMOD} ${SHAREMODE} ${PYTHONPREFIX_SITELIBDIR}/libtorrent.so

MASTERDIR=	${.CURDIR}/../libtorrent-rasterbar-15
.include "${MASTERDIR}/Makefile"

##
# information available after <bsd.port.pre.mk>
##
# insure python paths are correctly identified
CONFIGURE_ENV+=	PYTHON_INCLUDEDIR="${PYTHON_INCLUDEDIR}" \
		PYTHON_VERSION="${PYTHON_VERSION}"
# prefix PKGNAME with python- so that the egg info file is properly named.
PYDISTUTILS_PKGNAME=	python-${PORTNAME}
