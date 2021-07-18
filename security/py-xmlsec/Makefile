# Created by: ijliao

PORTNAME=	xmlsec
PORTVERSION=	1.3.11
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python bindings for XML Security Library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=3.8.0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pkgconfig>=0:devel/py-pkgconfig@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}
LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libxmlsec1-nss.so:security/xmlsec1
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis@${PY_FLAVOR}

USES=		gnome pkgconfig python:3.6+
USE_GNOME=	libxml2 libxslt
USE_PYTHON=	autoplist distutils flavors

INSTALL_TARGET=	install-strip

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/xmlsec*.so

do-test:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/pytest-${PYTHON_VER} tests

.include <bsd.port.mk>
