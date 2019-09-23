# $FreeBSD$

PORTNAME=		pyznap
DISTVERSIONPREFIX=	v
DISTVERSION=		1.4.3
CATEGORIES=		sysutils python
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	driesm.michiels@gmail.com
COMMENT=	ZFS snapshot tool written in Python

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	lzop:archivers/lzop \
		mbuffer:misc/mbuffer \
		pv:sysutils/pv

#TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=2.4.2:security/py-paramiko@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner@${PY_FLAVOR} \
#		faketime:devel/faketime

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

USE_GITHUB=	yes
GH_ACCOUNT=	yboetz

NO_ARCH=	yes
SUB_FILES=	pkg-message
SUB_LIST=	BINDIR=${PREFIX}/bin ETCDIR=${PREFIX}/etc

post-patch:
	${REINPLACE_CMD} -e 's|/etc/pyznap/|${PREFIX}/etc/pyznap/|g' ${WRKSRC}/${PORTNAME}/main.py

# upstream does not support selecting/deselecting tests from setuptools
# zfs tests work on the host but not in a poudriere jail
# ssh tests fail as priv/pub key auth is required to be set up in advance
#do-test:
#	@${CD} ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
