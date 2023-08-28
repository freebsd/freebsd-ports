PORTNAME=	borgmatic
PORTVERSION=	1.8.2
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Wrapper script for Borg backup software
WWW=		https://torsion.org/borgmatic/

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}borgbackup>=0:archivers/py-borgbackup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0:devel/py-ruamel.yaml@${PY_FLAVOR}
USES=		python
USE_PYTHON=	autoplist distutils

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
