# Created by: ijliao
# $FreeBSD$

PORTNAME=	xmlsec
PORTVERSION=	1.3.6
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python bindings for XML Security Library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=3.8.0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pkgconfig>=0:devel/py-pkgconfig@${PY_FLAVOR}
LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libxmlsec1-nss.so:security/xmlsec1

USES=		gnome pkgconfig python
USE_GITHUB=	yes
USE_GNOME=	libxml2 libxslt
USE_PYTHON=	autoplist distutils flavors

GH_ACCOUNT=	mehcode
GH_PROJECT=	python-xmlsec

INSTALL_TARGET=	install-strip

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/xmlsec.so

.include <bsd.port.mk>
