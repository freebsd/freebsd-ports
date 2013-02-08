# Created by: Charlie Kester <corky1951@comcast.net>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	multimedia python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Python bindings for the MLT multimedia framework

LICENSE=	GPLv2
LICENSE_COMB=	single

LIB_DEPENDS=	mlt:${PORTSDIR}/${MASTER_PORT}
BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13

USE_PYTHON=	yes
MASTERDIR=	${.CURDIR:H:H}/multimedia/mlt

PORTEXAMPLES=	python

PLIST=		# empty
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/_mlt.so \
		%%PYTHON_SITELIBDIR%%/mlt.py \
		%%PYTHON_SITELIBDIR%%/mlt.pyc \
		%%PYTHON_SITELIBDIR%%/mlt.pyo

BUILD_WRKSRC=	${WRKSRC}/src/swig/python
INSTALL_WRKSRC=	${BUILD_WRKSRC}

.include <bsd.port.options.mk>

do-build:
	@${REINPLACE_CMD} -e 's|-L../../mlt++|-L${LOCALBASE}/lib|' \
		-e 's|g++|${CXX} ${CXXFLAGS}|' \
		-e 's|-pthread|${PTHREAD_LIBS}|' \
		${BUILD_WRKSRC}/build
	@cd ${BUILD_WRKSRC} && ${SH} build

do-install:
	${INSTALL_LIB} ${INSTALL_WRKSRC}/_mlt.so ${PYTHONPREFIX_SITELIBDIR}
	${INSTALL_SCRIPT} ${INSTALL_WRKSRC}/mlt.py ${PYTHONPREFIX_SITELIBDIR}
	${PYTHON_CMD} -c 'import mlt'
	${PYTHON_CMD} -Oc 'import mlt'

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}/python
. for f in codecs getimage play waveforms
	${INSTALL_DATA} ${INSTALL_WRKSRC}/${f}.py ${EXAMPLESDIR}/python
. endfor
.endif

.include "${MASTERDIR}/Makefile"
