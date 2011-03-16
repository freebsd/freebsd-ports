# ex:ts=8
# Ports collection makefile for:	mlt
# Date created:		2011-02-06
# Whom:			Charlie Kester <corky1951@comcast.net>
#
# $FreeBSD$
#

PORTNAME=	mlt
PORTVERSION=	0.6.2
PORTREVISION=	1
CATEGORIES=	multimedia python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Python bindings for the MLT multimedia framework

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPL

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	mlt.3:${PORTSDIR}/multimedia/mlt

USE_PYTHON=	yes

PORTEXAMPLES=	python

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/_mlt.so \
		%%PYTHON_SITELIBDIR%%/mlt.py \
		%%PYTHON_SITELIBDIR%%/mlt.pyc \
		%%PYTHON_SITELIBDIR%%/mlt.pyo

BUILD_WRKSRC=	${WRKSRC}/src/swig/python
INSTALL_WRKSRC=	${BUILD_WRKSRC}

do-build:
	${REINPLACE_CMD} -e 's|-L../../mlt++|-L${LOCALBASE}/lib|g' \
		-e 's|g++|g++ ${CXXFLAGS}|g' \
		-e 's|-pthread|${PTHREAD_LIBS}|g' \
		${BUILD_WRKSRC}/build
	cd ${BUILD_WRKSRC} && ${SH} build

do-install:
	${INSTALL_LIB} ${INSTALL_WRKSRC}/_mlt.so ${PYTHONPREFIX_SITELIBDIR}
	${INSTALL_SCRIPT} ${INSTALL_WRKSRC}/mlt.py ${PYTHONPREFIX_SITELIBDIR}
	${PYTHON_CMD} -c 'import mlt'
	${PYTHON_CMD} -O -c 'import mlt'

post-install:
.ifndef(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/python
.for f in codecs play waveforms
	${INSTALL_DATA} ${INSTALL_WRKSRC}/${f}.py ${EXAMPLESDIR}/python
.endfor
.endif

.include <bsd.port.mk>
