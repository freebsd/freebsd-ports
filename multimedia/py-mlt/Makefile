# ex:ts=8
# Ports collection makefile for:	mlt
# Date created:		2011-02-06
# Whom:			Charlie Kester <corky1951@comcast.net>
#
# $FreeBSD$
#

PORTNAME=	mlt
PORTVERSION=	0.6.2
CATEGORIES=	multimedia python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Python bindings for the MLT multimedia framework

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	mlt.3:${PORTSDIR}/multimedia/mlt

USE_PYTHON=	yes

LICENSE=	GPLv2

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/_mlt.so \
		%%PYTHON_SITELIBDIR%%/mlt.py

do-build:
	(cd ${WRKSRC}/src/swig && \
	swig -c++ -I${LOCALBASE}/include/mlt -I${LOCALBASE}/include/mlt++ -python mlt.i && \
	g++ -fPIC -D_GNU_SOURCE -c -rdynamic -pthread -I${LOCALBASE}/include -I${LOCALBASE}/include/mlt -I${PYTHON_INCLUDEDIR} mlt_wrap.cxx && \
	g++ -shared mlt_wrap.o -L${LOCALBASE}/lib -lmlt++ -o _mlt.so)

do-install:
	${INSTALL_LIB} ${WRKSRC}/src/swig/_mlt.so ${PYTHONPREFIX_SITELIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/src/swig/mlt.py ${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
