PORTNAME=	mitogen
DISTVERSION=	0.3.27
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

# PATCH_SITES=	https://github.com/mitogen-hq/${PORTNAME}/pull/
# PATCHFILES+=	913.patch:-p1 # https://github.com/mitogen-hq/mitogen/pull/913.patch

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Ansible accelerator & python library for writing distributed programs
WWW=		https://mitogen.networkgenomics.com/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe python
CPE_VENDOR=	networkgenomics
USE_PYTHON=	distutils autoplist concurrent

NO_ARCH=	yes

SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
