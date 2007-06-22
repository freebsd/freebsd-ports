# New ports collection makefile for:	numpy
# Date created:				24 July 2006
# Whom:					Tony Maher
#
# $FreeBSD$
#

PORTNAME=	numpy
PORTVERSION=	1.0.2
PORTEPOCH=	1
CATEGORIES=	math python
MASTER_SITES=	http://numpy.scipy.org/:doc \
		${MASTER_SITE_SOURCEFORGE:S/$/:source/}
MASTER_SITE_SUBDIR=	numpy/:source
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	numpy-${PORTVERSION:S/r/rc/}${EXTRACT_SUFX}:source \
		numpy.pdf:doc
EXTRACT_ONLY=	numpy-${PORTVERSION:S/r/rc/}${EXTRACT_SUFX}

MAINTAINER=	db@FreeBSD.org
COMMENT=	The New Numeric Extension to Python

CONFLICTS=	f2py-*

OPTIONS=	ATLAS "Use optimized blas library" Off

WANT_FORTRAN=   yes #dummy
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

pre-fetch:
.if ${PYTHON_REL} < 200
	@${ECHO} "Py-numpy doesn't work with Python versions < 2.0."
	@${ECHO} "Please use the py-numeric17 port for these."
	@${FALSE}
.endif

post-extract:
	@${CP} ${DISTDIR}/numpy.pdf ${WRKDIR}

BUILD_DEPENDS+=	gfortran42:${PORTSDIR}/lang/gcc42
FC=		gfortran42
F77=		gfortran42
GCCLIBDIR=	`${FC} -print-file-name=`
post-patch:
.ifdef WITH_ATLAS
	@${CP} ${FILESDIR}/site.cfg ${WRKSRC}/site.cfg
	@${REINPLACE_CMD} -e "s+%%GCCLIBDIR%%+${GCCLIBDIR}+" \
	    -e "s+%%LOCALBASE%%+${LOCALBASE}+" \
	    -e "s+%%ATLASLIBS%%+alapack_r, f77blas_r, cblas_r, atlas_r+" \
		${WRKSRC}/site.cfg
.else
	@${CP} ${FILESDIR}/site.cfg ${WRKSRC}/site.cfg
	@${REINPLACE_CMD} -e "s+%%GCCLIBDIR%%+${GCCLIBDIR}+" \
	    -e "s+%%LOCALBASE%%+${LOCALBASE}+" \
	    -e "s+%%ATLASLIBS%%+lapack, blas+" \
		 ${WRKSRC}/site.cfg
.endif
	@${REINPLACE_CMD} -e "s+%%GCCLIBDIR%%+${GCCLIBDIR}+" ${WRKSRC}/numpy/distutils/system_info.py

post-install:
	${INSTALL_MAN} ${WRKSRC}/numpy/f2py/f2py.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/numpy.pdf ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
