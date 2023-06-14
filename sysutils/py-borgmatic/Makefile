PORTNAME=	borgmatic
PORTVERSION=	1.5.24
PORTREVISION=	2
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
		${PYTHON_PKGNAMEPREFIX}pykwalify>=0:textproc/py-pykwalify@${PY_FLAVOR} \
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
		borgmatic/commands/borgmatic.py \
		borgmatic/commands/convert_config.py \
		borgmatic/commands/generate_config.py \
		borgmatic/config/collect.py \
		borgmatic/config/convert.py \
		borgmatic/config/schema.yaml \
		tests/unit/config/test_collect.py

.include <bsd.port.post.mk>
