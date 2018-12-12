# Created by: antoine@FreeBSD.org
# $FreeBSD$

PORTNAME=	rekall
DISTVERSION=	1.7.2rc1
PORTREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Memory forensics analysis framework

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rekall_lib>=1.7.1:security/py-rekall_lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rekall-core>=1.7.1:security/py-rekall-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython5>=5.0.0:devel/ipython5@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python shebangfix zip
USE_PYTHON=	distutils autoplist

python_OLD_CMD=	python
SHEBANG_FILES=	tools/devel/autopep8.sh \
		tools/devel/presubmit.sh \
		tools/linux/lmap/tools/fix_versions.py \
		tools/profiles/unpack_kdbg_kit.py \
		tools/testing/tap.py \
		tools/testing/test_suite.py \
		tools/windows/winpmem/winpmem.py

.include <bsd.port.pre.mk>

PYDISTUTILS_INSTALLARGS+=--install-data ${DATADIR}

.include <bsd.port.post.mk>
