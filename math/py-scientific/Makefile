# New ports collection makefile for:	py-scientific
# Version required:	2.0b1
# Date created:		29 July 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	ScientificPython-2.0b1
PKGNAME=	py-scientific-2.0b1
CATEGORIES=	math python
MASTER_SITES=	http://starship.python.net/crew/hinsen/ \
		http://dirac.cnrs-orleans.fr/programs/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python \
		${NUMPYDIR}/Numeric.py:${PORTSDIR}/math/numpy
LIB_DEPENDS=	netcdf.1:${PORTSDIR}/math/netcdf
RUN_DEPENDS=	python:${PORTSDIR}/lang/python \
		${NUMPYDIR}/Numeric.py:${PORTSDIR}/math/numpy

WRKSRC=		${WRKDIR}/${DISTNAME}/Src

PYTHONSCRIPTDIR=	${PREFIX}/lib/python1.5
NUMPYDIR=	${PYTHONSCRIPTDIR}/site-packages/numerical
SCIENTIFICDIR=	${PYTHONSCRIPTDIR}/site-packages/Scientific
DOCDIR=		${PREFIX}/share/doc/py-scientific
EXAMPLEDIR=	${PREFIX}/share/examples/py-scientific

post-extract:
	@${CP} ${FILESDIR}/Setup ${WRKSRC}
	@${CP} ${PYTHONSCRIPTDIR}/config/Makefile.pre.in ${WRKSRC}

do-configure:
	@(cd ${WRKSRC} && ${CONFIGURE_ENV} ${MAKE} -f Makefile.pre.in boot)

post-install:
	cd ${WRKDIR}/${DISTNAME}; tar cf - Scientific | \
	    (cd ${PYTHONSCRIPTDIR}/site-packages; tar xf -)
	@${PREFIX}/bin/python ${PYTHONSCRIPTDIR}/compileall.py ${SCIENTIFICDIR}
	@${PREFIX}/bin/python -O ${PYTHONSCRIPTDIR}/compileall.py ${SCIENTIFICDIR}
	@${MKDIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/Examples/* ${EXAMPLEDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	cd ${WRKDIR}/${DISTNAME}/Doc; tar cf - . | \
	    (cd ${DOCDIR}; tar xf -)
.endif

.include <bsd.port.mk>
