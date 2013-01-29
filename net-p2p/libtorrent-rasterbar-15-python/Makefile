# $FreeBSD$

PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Python bindings for libtorrent-rasterbar-15
CATEGORIES=	net-p2p python

USE_PYTHON=	yes

LIB_DEPENDS+=	boost_python.4:${PORTSDIR}/devel/boost-python-libs \
		torrent-rasterbar.6:${PORTSDIR}/net-p2p/libtorrent-rasterbar-15

BUILD_WRKSRC=	${WRKSRC}/bindings/python
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PLIST=		${.CURDIR}/pkg-plist

INSTALLS_EGGINFO=	yes
PYDISTUTILS_PKGNAME=	python_libtorrent

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
