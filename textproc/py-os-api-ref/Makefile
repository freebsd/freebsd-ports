PORTNAME=	os-api-ref
DISTVERSION=	3.1.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	os_api_ref-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Sphinx Extensions to support API reference sites in OpenStack
WWW=		https://docs.openstack.org/os-api-ref/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=3.12:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=4.0.0,1:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openstackdocstheme>=2.2.1:textproc/py-openstackdocstheme@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517
NO_ARCH=	yes

.include <bsd.port.mk>
