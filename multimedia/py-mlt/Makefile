# Created by: Charlie Kester <corky1951@comcast.net>
# $FreeBSD$

PORTREVISION=	1
CATEGORIES=	multimedia python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python bindings for the MLT multimedia framework

LICENSE=	GPLv2
LICENSE_COMB=	single

LIB_DEPENDS=	libmlt.so:${PORTSDIR}/${MASTER_PORT}
BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13

USE_PYTHON=	yes
MASTERDIR=	${.CURDIR:H:H}/multimedia/mlt

EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}/python
PORTEXAMPLES=	*

PLIST=		${.CURDIR}/pkg-plist

BUILD_WRKSRC=	${WRKSRC}/src/swig/python
INSTALL_WRKSRC=	${BUILD_WRKSRC}

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-L../../mlt++|-L${LOCALBASE}/lib|' \
		-e 's|g++|${CXX} ${CXXFLAGS}|' \
		${BUILD_WRKSRC}/build

do-build:
	@cd ${BUILD_WRKSRC} && ${SH} build

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${INSTALL_LIB} ${INSTALL_WRKSRC}/_mlt.so ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${INSTALL_SCRIPT} ${INSTALL_WRKSRC}/mlt.py ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	@cd ${STAGEDIR}${PYTHON_SITELIBDIR} && ${PYTHON_CMD} -c 'import mlt'
	@cd ${STAGEDIR}${PYTHON_SITELIBDIR} && ${PYTHON_CMD} -Oc 'import mlt'
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
. for f in codecs getimage play waveforms
	${INSTALL_DATA} ${INSTALL_WRKSRC}/${f}.py ${STAGEDIR}${EXAMPLESDIR}
. endfor

.include "${MASTERDIR}/Makefile"
