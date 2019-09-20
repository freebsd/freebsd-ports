# $FreeBSD$

PORTNAME=	veles
DISTVERSION=	2018.05.0
PORTREVISION=	2
CATEGORIES=	misc

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	f9125454bfb2cd28d78544ba41d92c028be6a277.patch:-p1 # Lift the default size limit of 1MB that msgpack imposes on binary data: https://github.com/codilime/veles/pull/447

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool for binary data visualization and analysis

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE-2.0

PYTHON_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbr>0:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
BUILD_DEPENDS=	msgpack>0:devel/msgpack \
		${PYTHON_DEPENDS}
RUN_DEPENDS=	${PYTHON_DEPENDS}

USES=		cmake python:3.6+ qt:5 shebangfix
SHEBANG_GLOB=	*.py
SHEBANG_FILES=	python/plugin python/proxy resources/install/postinst python/test_dis
USE_GITHUB=	yes
GH_ACCOUNT=	codilime
USE_QT=		core gui network widgets buildtools_build qmake_build

CMAKE_ARGS=	-DFREEBSD_PYTHON_CMD:STRING=${PYTHON_CMD} \
		-DFREEBSD_PYTHON_EXENAME:STRING=${PYTHON_CMD:C/.*\///} \
		-DFREEBSD_LLVM_VERSION:STDING=${LLVM_DEFAULT} \
		-DFREEBSD_PYTHON_SITELIBDIR:STRING=${PYTHON_SITELIBDIR} \
		-DMSGPACK_INCLUDE_PATH:STRING=${LOCALBASE}/include/mgpack

# veles needs clang-format and clang-tidy that are only provided by the port
BUILD_DEPENDS+=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
CPP=		clang-cpp${LLVM_DEFAULT}
CC=		clang${LLVM_DEFAULT}
CXX=		clang++${LLVM_DEFAULT}

post-patch:
	@${REINPLACE_CMD} 's|QString python_interpreter_executable("/usr/local/bin/python3");|QString python_interpreter_executable("${PYTHON_CMD}");|' \
		${WRKSRC}/src/ui/connectionmanager.cc

post-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}
	cd ${WRKSRC}/python/veles && ${COPYTREE_SHARE} . ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/python/srv.py ${STAGEDIR}${PREFIX}/bin/veles-server

.include <bsd.port.mk>
