# $FreeBSD$

PORTNAME=	pyteomics
PORTVERSION=	4.3.2
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python modules for proteomics data analysis

LICENSE=	APACHE20

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	DF GRAPHICS TDA UNIMOD XML
OPTIONS_DEFAULT=DF GRAPHICS TDA UNIMOD XML
DF_DESC=	DataFrame support
GRAPHICS_DESC=	Graphics support
TDA_DESC=	Target-decoy approach support
UNIMOD_DESC=	Unimod database support
XML_DESC=	XML support	

DF_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}pandas>=0:math/py-pandas@${PY_FLAVOR}
GRAPHICS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR}
TDA_RUN_DEPENDS=	${PYNUMPY}
UNIMOD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sqlalchemy13>=0:databases/py-sqlalchemy13@${PY_FLAVOR}
XML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
			${PYNUMPY}

.include <bsd.port.mk>
