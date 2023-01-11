PORTNAME=	openbabel
DISTVERSION=	3.1.1.1
CATEGORIES=	science # chemistry
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Chemical toolbox designed to speak the many languages of chemical data
WWW=		https://openbabel.org/wiki/Main_Page

LICENSE=	GPLv2+

BUILD_DEPENDS=	swig:devel/swig
LIB_DEPENDS=	libopenbabel.so:science/openbabel

USES=		python
USE_PYTHON=	distutils autoplist

BINARY_ALIAS=	python=${PYTHON_CMD}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/openbabel/_openbabel${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
