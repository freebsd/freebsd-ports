PORTNAME=	libscep
DISTVERSIONPREFIX=	v
DISTVERSION=	0.09
CATEGORIES=	security

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Client side SCEP library w/o clients

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/README.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR} \
		check>=0.12.0:devel/check \
		curl>=7.64:ftp/curl \
		uriparser>=0.9.1:net/uriparser
RUN_DEPENDS=	check>=0.12.0:devel/check \
		curl>=7.64:ftp/curl \
		uriparser>=0.9.1:net/uriparser

USES=		cmake:noninja gmake libtool pkgconfig python:build,3.6+ ssl
USE_GITHUB=	yes
GH_ACCOUNT=	openxpki
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DCHECK_INSTALL_DIR=${PREFIX}
CMAKE_OFF=	BUILD_CLI

PLIST_FILES=	include/scep.h \
		lib/libscep.so \
		man/man1/libscep.1.gz

post-build:
	(cd ${WRKSRC}/docs;\
	BUILDDIR=${BUILD_WRKSRC} SPHINXBUILD=sphinx-build-${PYTHON_VER} ${GMAKE} -e man)

post-install:
	${INSTALL_MAN} ${BUILD_WRKSRC}/man/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
