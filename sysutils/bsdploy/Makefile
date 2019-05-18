# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bsdploy
PORTVERSION=	2.3.0
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Tool to remotely provision, configure and maintain FreeBSD jails

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyliblzma>0:archivers/py-pyliblzma@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ploy>=1.5.0:sysutils/py-ploy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ploy_ansible>=1.3.0:sysutils/py-ploy_ansible@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ploy_ezjail>=1.2.0:sysutils/py-ploy_ezjail@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ploy_fabric>=1.1.0:sysutils/py-ploy_fabric@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=2.4.2:devel/py-pytest@${PY_FLAVOR}

USES=			python:-2.7
USE_PYTHON=		autoplist concurrent distutils

OPTIONS_DEFINE=		EC2
OPTIONS_DEFAULT=	EC2

EC2_DESC=		Support Amazon Web Services EC2 hosts
EC2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ploy_ec2>0:sysutils/py-ploy_ec2@${PY_FLAVOR}

NO_ARCH=	yes

do-test:
	${RM} ${WRKSRC}/pytest.ini
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs -k 'not test_virtualbox'

.include <bsd.port.mk>
