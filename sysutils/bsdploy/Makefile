# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bsdploy
PORTVERSION=	2.1.0
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Container Management for FreeBSD Jails

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyliblzma>0:archivers/py-pyliblzma@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ploy>=1.2.0:sysutils/py-ploy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ploy_ansible>=1.3.0:sysutils/py-ploy_ansible@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ploy_ezjail>=1.2.0:sysutils/py-ploy_ezjail@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ploy_fabric>=1.1.0:sysutils/py-ploy_fabric@${PY_FLAVOR}

OPTIONS_DEFINE=		EC2
OPTIONS_DEFAULT=	EC2

EC2_DESC=		Support Amazon Web Services EC2 hosts
EC2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ploy_ec2>0:sysutils/py-ploy_ec2@${PY_FLAVOR}

USES=			python:-2.7 zip
USE_PYTHON=		autoplist distutils

NO_ARCH=	yes

post-extract:
	${RM} ${WRKSRC}/pytest.ini

.include <bsd.port.mk>
