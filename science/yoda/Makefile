PORTNAME=	yoda
DISTVERSION=	2.1.4
CATEGORIES=	science
MASTER_SITES=	https://yoda.hepforge.org/downloads/
DISTNAME=	${PORTNAME:tu}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Particle physics package with classes for data analysis, histogramming
WWW=		https://yoda.hepforge.org/

LICENSE=	GPLv3

LIB_DEPENDS=	libhdf5.so:science/hdf5
TEST_DEPENDS=	bash:shells/bash \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR}

USES=		compiler:c++11-lang gettext-runtime gmake libtool localbase:ldflags shebangfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

SHEBANG_GLOB=	*.py *.sh
SHEBANG_FILES=	bin/root2yoda

TEST_TARGET=	check # doesn't report summary in the end, see https://gitlab.com/hepcedar/yoda/-/issues/49

PLIST_SUB=	VERSION=${PORTVERSION}

OPTIONS_DEFINE=		PYTHON
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

PYTHON_USES=			python
PYTHON_USE=			PYTHON=cython
PYTHON_CONFIGURE_ENABLE=	pyext
PYTHON_MAKE_ENV=		PYTHON_VERSION=${PYTHON_VER} PYTHON=${PYTHON_CMD}
PYTHON_VARS=			SHEBANG_FILES="bin/${PORTNAME}* bin/root2yoda" \
				BINARY_ALIAS="python=${PYTHON_CMD}"

TEST_ENV=	${MAKE_ENV} PATH=${STAGEDIR}${PREFIX}/bin:${PATH} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MPYTHON}
USES+=	python:test
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libYODA.so

post-install-PYTHON-on:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/*.so

post-install-PYTHON-off:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/${PORTNAME:tu}

# ============================================================================
# Testsuite summary for YODA 2.1.4
# ============================================================================
# TOTAL: 77
# PASS:  77
# SKIP:  0
# XFAIL: 0
# FAIL:  0
# XPASS: 0
# ERROR: 0

.include <bsd.port.mk>
