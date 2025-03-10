PORTNAME=	yoda
DISTVERSION=	2.0.2
CATEGORIES=	science
MASTER_SITES=	https://yoda.hepforge.org/downloads/
DISTNAME=	${PORTNAME:tu}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Particle physics package with classes for data analysis, histogramming
WWW=		https://yoda.hepforge.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	bash:shells/bash \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR}

USES=		compiler:c++11-lang gettext-runtime gmake libtool shebangfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

SHEBANG_GLOB=	*.py *.sh

TEST_TARGET=	check # doesn't report summary in the end, see https://gitlab.com/hepcedar/yoda/-/issues/49

PLIST_SUB=	VERSION=${PORTVERSION}

OPTIONS_DEFINE=		PYTHON
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

PYTHON_USES=			python
PYTHON_USE=			PYTHON=cython
PYTHON_CONFIGURE_ENABLE=	pyext
PYTHON_MAKE_ENV=		PYTHON_VERSION=${PYTHON_VER} PYTHON=${PYTHON_CMD}
PYTHON_VARS=			SHEBANG_FILES="bin/${PORTNAME}*" \
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

.include <bsd.port.mk>
