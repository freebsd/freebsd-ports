# $FreeBSD$

PORTNAME=	python-augeas
PORTVERSION=	1.0.3
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	johan@stromnet.se
COMMENT=	Pure python bindings for Augeas

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

py34_BROKEN=	does not package
py35_BROKEN=	does not package
py36_BROKEN=	does not package

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.1.0:devel/py-cffi@${FLAVOR}
LIB_DEPENDS=	libaugeas.so:textproc/augeas

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	distutils

GH_ACCOUNT=	hercules-team

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${WRKSRC}/test/test_augeas.py

.include <bsd.port.mk>
