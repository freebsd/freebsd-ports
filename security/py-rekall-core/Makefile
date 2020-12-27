# Created by: antoine@FreeBSD.org
# $FreeBSD$

PORTNAME=	rekall-core
DISTVERSION=	1.7.2rc1-52
DISTVERSIONSUFFIX=	-g0cba831
PORTREVISION=	1
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	CORE component of the Rekall framework

LICENSE=	GPLv2

DEPRECATED=	Unmaintained upstream
EXPIRATION_DATE=	2021-01-27

RUN_DEPENDS=	cabextract:archivers/cabextract \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}acora>=2.0:textproc/py-acora@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}arrow>=0.10.0:devel/py-arrow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}artifacts>=20170909:security/py-artifacts@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}intervaltree>=2.1.0:devel/py-intervaltree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipaddr>=2.2.0:devel/py-ipaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parsedatetime>=2.4:devel/py-parsedatetime@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=5.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyaff4>=0.25:security/py-pyaff4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodomex>=3.4.7:security/py-pycryptodomex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyelftools>=0.24:devel/py-pyelftools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=2.1.5:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.6.1:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytsk>=20170802:sysutils/py-pytsk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2017.3,1:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}capstone>=3.0.4:devel/py-capstone@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rekall-efilter>=1.6:devel/py-rekall-efilter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rekall_lib>=0:security/py-rekall_lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yara>=3.6:security/py-yara@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_PROJECT=	rekall

USES=		python:3.5+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes
WRKSRC_SUBDIR=	rekall-core

.include <bsd.port.pre.mk>

PYDISTUTILS_INSTALLARGS+=	--install-data=${PYTHON_SITELIBDIR}

post-patch:
	${REINPLACE_CMD} "s|from Crypto|from Cryptodome|" \
		${WRKSRC}/rekall/compatibility.py \
		${WRKSRC}/rekall/plugins/windows/mimikatz.py \
		${WRKSRC}/rekall/plugins/windows/registry/hashdump.py \
		${WRKSRC}/rekall/plugins/windows/registry/lsasecrets.py

.include <bsd.port.post.mk>
