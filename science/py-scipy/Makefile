# Ports collection makefile for:	SciPy
# Date created:			Jun 8, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	scipy
PORTVERSION=	0.7.0
PORTREVISION=	2
CATEGORIES=	science python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	llwang@infor.org
COMMENT=	Scientific tools for Python

BUILD_DEPENDS+=	${PYNUMPY} \
		${LOCALBASE}/lib/libdjbfft.a:${PORTSDIR}/math/djbfft
LIB_DEPENDS=	fftw.2:${PORTSDIR}/math/fftw

LATEST_LINK=	py-${PORTNAME}
OPTIONSFILE=	${PORT_DBDIR}/py-numpy/options

USE_FORTRAN=	yes
USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes
USE_WX=		2.4-2.6
WX_COMPS=	python:build python:run
OPTIONS=	ATLAS "Use optimized blas library" OFF

post-patch:
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e "s@malloc\.h@stdlib.h@"

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" && ${OSVERSION} < 602101
BROKEN=	ldexpf is missing See http://lists.freebsd.org/pipermail/freebsd-amd64/2006-December/009263.html for details
.endif

.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
.if !exists(${LOCALBASE}/lib/libalapack.a)
IGNORE=		atlas needs to be built with WITH_STATICLIB for scipy to function properly
.endif
.else
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack \
		blas.2:${PORTSDIR}/math/blas
.endif

.if exists(${LOCALBASE}/lib/libumfpack.so.1)
BUILD_DEPENDS+=	swig:${PORTSDIR}/devel/swig13
LIB_DEPENDS+=	umfpack.1:${PORTSDIR}/math/suitesparse
.endif

PYDISTUTILS_CONFIGUREARGS+=	--fcompiler=gnu95
PYDISTUTILS_BUILDARGS+=	--fcompiler=gnu95

post-install:
	@${FIND} ${PYTHONPREFIX_SITELIBDIR}/scipy ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PYTHONPREFIX_SITELIBDIR}/scipy -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.post.mk>
