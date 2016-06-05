# Created by: Carlos J Puga Medina <cpm@fbsd.es>
# $FreeBSD$

PORTNAME=	sphinxcontrib-programoutput
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	Sphinx extension to include program output

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=1.1.3:textproc/py-sphinx
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=2.2:devel/py-pytest

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest

.include <bsd.port.mk>
