# $FreeBSD$

PORTNAME=	python-augeas
PORTVERSION=	0.5.0
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	johan@stromnet.se
COMMENT=	Pure python bindings for Augeas

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libaugeas.so:textproc/augeas

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	distutils autoplist

GH_ACCOUNT=	hercules-team

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${WRKSRC}/test/test_augeas.py

.include <bsd.port.mk>
