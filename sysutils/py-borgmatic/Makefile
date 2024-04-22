PORTNAME=	borgmatic
PORTVERSION=	1.8.8
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Wrapper script for Borg backup software
WWW=		https://torsion.org/borgmatic/

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}borgbackup>=0:archivers/py-borgbackup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0:devel/py-ruamel.yaml@${PY_FLAVOR}
USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} == "3.8"
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pkgutil-resolve-name>=1.3.10:devel/py-pkgutil-resolve-name@${PY_FLAVOR}
.endif

post-patch:
	@cd ${WRKSRC} && \
	  ${REINPLACE_CMD} -e 's|/etc/borgmatic|${PREFIX}/etc/borgmatic|g' \
		borgmatic/config/collect.py \
		borgmatic/config/schema.yaml \
		tests/unit/config/test_collect.py \
		tests/unit/borg/test_create.py

.include <bsd.port.post.mk>
