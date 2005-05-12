# ex:ts=8
# Ports collection makefile for:	SciPy
# Date created:			Jun 8, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	scipy
PORTVERSION=	0.3
CATEGORIES=	science python
MASTER_SITES=	http://www.scipy.org/download/scipy/src/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SciPy_complete-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scientific tools for Python

BUILD_DEPENDS=	${PYNUMERIC} \
		${LOCALBASE}/lib/libdjbfft.a:${PORTSDIR}/math/djbfft \
		f2py:${PORTSDIR}/lang/f2py \
		${PYTHON_SITELIBDIR}/wx/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython24
LIB_DEPENDS=	fftw.2:${PORTSDIR}/math/fftw \
		atlas.1:${PORTSDIR}/math/atlas

USE_REINPLACE=	yes
USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes

post-patch:
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e "s@malloc\.h@stdlib.h@"

.include <bsd.port.pre.mk>

post-install:
.for dir in ${PYTHON_SITELIBDIR}/gui_thread ${PYTHON_SITELIBDIR}/scipy \
		${PYTHON_SITELIBDIR}/scipy_base ${PYTHON_SITELIBDIR}/scipy_distutils \
		${PYTHON_SITELIBDIR}/scipy_test ${PYTHON_SITELIBDIR}/weave
	@${FIND} ${dir} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${dir} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endfor

.include <bsd.port.post.mk>
