# Created by: Charlie Kester <corky1951@comcast.net>
# $FreeBSD$

PORTREVISION=	2
CATEGORIES=	multimedia python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

USES=		python:2.7
USE_PYTHON=	flavors
MASTERDIR=	${.CURDIR:H}/mlt
SLAVEPORT=	swig Python

PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's,which python,which ${PYTHON_VERSION},' -e 's,python -c,${PYTHON_VERSION} -c,' \
			  -e 's,python-config,${PYTHON_VERSION}-config,' ${WRKSRC}/src/swig/python/build

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${INSTALL_LIB} ${INSTALL_WRKSRC}/_mlt.so ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${INSTALL_SCRIPT} ${INSTALL_WRKSRC}/mlt.py ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	@cd ${STAGEDIR}${PYTHON_SITELIBDIR} && ${PYTHON_CMD} -c 'import mlt'
	@cd ${STAGEDIR}${PYTHON_SITELIBDIR} && ${PYTHON_CMD} -Oc 'import mlt'

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in codecs getimage play switcher waveforms webvfx_generator
	${INSTALL_DATA} ${INSTALL_WRKSRC}/${f}.py ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include "${MASTERDIR}/Makefile"
