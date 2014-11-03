# Created by: Tony Maher
# $FreeBSD$

PORTNAME=	numpy
PORTVERSION=	1.9.1
PORTEPOCH=	1
CATEGORIES=	math python
MASTER_SITES=	http://docs.scipy.org/doc/${PORTNAME}/:doc \
		SF/${PORTNAME}/NumPy/${PORTVERSION}:source
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	numpy-${PORTVERSION:S/r/rc/}${EXTRACT_SUFX}:source \
		numpy-ref-${PORTVERSION}.pdf:doc \
		numpy-user-${PORTVERSION}.pdf:doc
EXTRACT_ONLY=	numpy-${PORTVERSION:S/r/rc/}${EXTRACT_SUFX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	The New Numeric Extension to Python

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	nosetests:${PORTSDIR}/devel/py-nose

USES=		fortran python
USE_PYTHON=	concurrent distutils py3kplist
LDFLAGS+=	-shared

OPTIONS_DEFINE=		ATLAS SUITESPARSE DOCS
OPTIONS_DEFAULT=	SUITESPARSE
ATLAS_DESC=		Use optimized blas library
SUITESPARSE_DESC=	Use AMD and UMFPACK in SuiteSparse

PYDISTUTILS_CONFIGUREARGS+=	--fcompiler=gnu95
PYDISTUTILS_BUILDARGS+=		--fcompiler=gnu95

PORTDOCS=	*
WRKSRC=		${WRKDIR}/${DISTNAME:S/r/rc/}

ATLAS_LIB_DEPENDS=	libatlas.so:${PORTSDIR}/math/atlas
ATLAS_LIB_DEPENDS_OFF=	libblas.so:${PORTSDIR}/math/blas \
			liblapack.so:${PORTSDIR}/math/lapack
SUITESPARSE_LIB_DEPENDS=libumfpack.so:${PORTSDIR}/math/suitesparse

.include <bsd.port.pre.mk>

PLIST_SUB+=	PYTHON_VER=${PYTHON_VER}
.if ${PYTHON_VERSION} == ${PYTHON_DEFAULT_VERSION}
PLIST_FILES+=	man/man1/f2py.1.gz
.endif

post-patch:
	${REINPLACE_CMD} -e "s+%%FC%%+${FC}+" ${WRKSRC}/numpy/distutils/fcompiler/gnu.py
	${CP} ${FILESDIR}/site.cfg ${WRKSRC}/site.cfg

GCCLIBDIR_CMDS=	${FC} -print-file-name=libgfortran.so|${SED} -e s/libgfortran.so//

pre-configure:
.if ${PORT_OPTIONS:MATLAS}
	@${REINPLACE_CMD} -e "s+%%ATLASLIBS%%+alapack, f77blas, cblas, atlas+" ${WRKSRC}/site.cfg
.else
	@${REINPLACE_CMD} -e "s+%%ATLASLIBS%%+lapack, blas+" ${WRKSRC}/site.cfg
.endif
.if !${PORT_OPTIONS:MSUITESPARSE}
	@${REINPLACE_CMD} -e "s+:%%LOCALBASE%%/include/suitesparse++" ${WRKSRC}/site.cfg
.endif
	@${REINPLACE_CMD} -e "s+%%GCCLIBDIR%%+$$(${GCCLIBDIR_CMDS})+" \
	    -e "s+%%LOCALBASE%%+${LOCALBASE}+g" \
		${WRKSRC}/site.cfg
	@${REINPLACE_CMD} -e "s+%%GCCLIBDIR%%+$$(${GCCLIBDIR_CMDS})+" ${WRKSRC}/numpy/distutils/system_info.py

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/f2py/f2py.1 ${STAGEDIR}${MANPREFIX}/man/man1/f2py-${PYTHON_VER}.1
.if ${PYTHON_VERSION} == ${PYTHON_DEFAULT_VERSION}
	${LN} -sf ${MANPREFIX}/man/man1/f2py-${PYTHON_VER}.1 ${STAGEDIR}${MANPREFIX}/man/man1/f2py.1
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/numpy-ref-${PORTVERSION}.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/numpy-user-${PORTVERSION}.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
