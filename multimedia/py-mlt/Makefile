# Created by: Charlie Kester <corky1951@comcast.net>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	multimedia python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

BUILD_DEPENDS=	python:lang/python

USES=		python:2
MASTERDIR=	${.CURDIR:H}/mlt
SLAVEPORT=	swig Python

PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

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
