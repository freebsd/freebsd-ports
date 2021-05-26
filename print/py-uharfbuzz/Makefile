# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	uharfbuzz
PORTVERSION=	0.16.1
CATEGORIES=	print python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Streamlined Cython bindings for the harfbuzz shaping engine

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR}
LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		compiler:c++11-lang python:3.6+ zip
USE_PYTHON=	autoplist concurrent cython distutils

post-patch:
	@${RM} -fr ${WRKSRC}/harfbuzz/
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/setup.py ${WRKSRC}/src/uharfbuzz/_harfbuzz.cpp

.include <bsd.port.mk>
