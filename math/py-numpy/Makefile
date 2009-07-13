# New ports collection makefile for:	numpy
# Date created:				24 July 2006
# Whom:					Tony Maher
#
# $FreeBSD$
#

PORTNAME=	numpy
PORTVERSION=	1.3.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	math python
MASTER_SITES=	http://numpy.scipy.org/:doc \
		${MASTER_SITE_SOURCEFORGE:S/$/:source/}
MASTER_SITE_SUBDIR=	numpy/:source
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	numpy-${PORTVERSION:S/r/rc/}${EXTRACT_SUFX}:source \
		numpybook.pdf:doc
EXTRACT_ONLY=	numpy-${PORTVERSION:S/r/rc/}${EXTRACT_SUFX}

MAINTAINER=	llwang@infor.org
COMMENT=	The New Numeric Extension to Python

RUN_DEPENDS=	nosetests:${PORTSDIR}/devel/py-nose

OPTIONS=	ATLAS "Use optimized blas library" Off

USE_FORTRAN=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
MAN1=		f2py.1

LATEST_LINK=	py-${PORTNAME}
WRKSRC=	${WRKDIR}/${DISTNAME:S/r/rc/}

.include <bsd.port.pre.mk>

.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
.if !exists(${LOCALBASE}/lib/libalapack.a)
IGNORE=	atlas needs to be built with WITH_STATICLIB for numpy to function properly
.endif
.else
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack \
		blas.2:${PORTSDIR}/math/blas
.endif

.if exists(${LOCALBASE}/lib/libumfpack.so.1)
LIB_DEPENDS+=	umfpack.1:${PORTSDIR}/math/suitesparse
.endif

PYDISTUTILS_CONFIGUREARGS+=	--fcompiler=gnu95
PYDISTUTILS_BUILDARGS+=	--fcompiler=gnu95

post-extract:
	@${CP} ${DISTDIR}/numpybook.pdf ${WRKDIR}

post-patch:
	@${REINPLACE_CMD} -e "s+%%FC%%+${FC}+" ${WRKSRC}/numpy/distutils/fcompiler/gnu.py
	@${CP} ${FILESDIR}/site.cfg ${WRKSRC}/site.cfg

GCCLIBDIR=	`${FC} -print-file-name=libgfortran.so|${SED} -e s/libgfortran.so//`
pre-configure:
.ifdef WITH_ATLAS
	@${REINPLACE_CMD} -e "s+%%GCCLIBDIR%%+${GCCLIBDIR}+" \
	    -e "s+%%LOCALBASE%%+${LOCALBASE}+g" \
	    -e "s+%%ATLASLIBS%%+alapack_r, f77blas_r, cblas_r, atlas_r+" \
		${WRKSRC}/site.cfg
.else
	@${REINPLACE_CMD} -e "s+%%GCCLIBDIR%%+${GCCLIBDIR}+" \
	    -e "s+%%LOCALBASE%%+${LOCALBASE}+g" \
	    -e "s+%%ATLASLIBS%%+lapack, blas+" \
		 ${WRKSRC}/site.cfg
.endif
	@${REINPLACE_CMD} -e "s+%%GCCLIBDIR%%+${GCCLIBDIR}+" ${WRKSRC}/numpy/distutils/system_info.py

post-install:
	${INSTALL_MAN} ${WRKSRC}/numpy/f2py/f2py.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/numpybook.pdf ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
