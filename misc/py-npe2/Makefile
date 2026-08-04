PORTNAME=	npe2
DISTVERSION=	0.8.3
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Napari plugin engine v2
WWW=		https://napari.org/stable/plugins/ \
		https://github.com/napari/npe2

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}build>=1:devel/py-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=4.3.0:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psygnal>=0.3.0:devel/py-psygnal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-extra-types>=2.8:devel/py-pydantic-extra-types@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.8:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=14.0.0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli-w>=1.0.0:textproc/py-tomli-w@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.15.4:devel/py-typer@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

# tests disabled: upstream test suite has 3 known failures and requires
# heavy napari plugin stack, see https://github.com/napari/npe2/issues/409

.include <bsd.port.mk>
