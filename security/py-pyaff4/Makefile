# Created by: antoine@FreeBSD.org
# $FreeBSD$

PORTNAME=	pyaff4
DISTVERSION=	0.26.post6
CATEGORIES=	security devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python Advanced Forensic Format Version 4 library

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>=0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-snappy>=0.5.1:archivers/py-python-snappy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rdflib>=4.2.2:textproc/py-rdflib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}intervaltree>=2.1.0:devel/py-intervaltree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyblake2>=0.9.3:security/py-pyblake2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}expiringdict>=1.1.4:devel/py-expiringdict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5lib>=0:www/py-html5lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
