PORTNAME=	natten
DISTVERSION=	0.17.1
PORTREVISION=	2
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Neighborhood Attention Extension
WWW=		https://shi-labs.com/natten/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake-core \
		pybind11>0:devel/pybind11 \
		${PYTHON_PKGNAMEPREFIX}pytorch>=2.0.0:misc/py-pytorch@${PY_FLAVOR}
LIB_DEPENDS=	libabsl_str_format_internal.so:devel/abseil \
		libprotobuf.so:devel/protobuf
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>=2.0.0:misc/py-pytorch@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

post-install:
	# strip binary
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/natten/libnatten${PYTHON_EXT_SUFFIX}.so
	# delete stray files, see https://github.com/SHI-Labs/NATTEN/issues/152
	@${RM} -r \
		${STAGEDIR}${PYTHON_SITELIBDIR}/CMakeFiles \
		${STAGEDIR}${PYTHON_SITELIBDIR}/CMakeCache.txt \
		${STAGEDIR}${PYTHON_SITELIBDIR}/cmake_install.cmake \
		${STAGEDIR}${PYTHON_SITELIBDIR}/Makefile

.include <bsd.port.mk>
