PORTNAME=	pyaff4
DISTVERSION=	0.26.post6
PORTREVISION=	3
CATEGORIES=	security devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python Advanced Forensic Format Version 4 library
WWW=		https://www.aff4.org/

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>=0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-snappy>=0.5.1:archivers/py-python-snappy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rdflib>=4.2.2:textproc/py-rdflib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}intervaltree>=2.1.0:devel/py-intervaltree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}expiringdict>=1.1.4:devel/py-expiringdict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5lib>=0:www/py-html5lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynacl>0:security/py-pynacl@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
