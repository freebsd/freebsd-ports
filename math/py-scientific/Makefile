# New ports collection makefile for:	py-scientific
# Date created:		29 July 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scientific
PORTVERSION=	2.0b1
CATEGORIES=	math python
MASTER_SITES=	http://starship.python.net/crew/hinsen/ \
		http://dirac.cnrs-orleans.fr/programs/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ScientificPython-${PORTVERSION}

MAINTAINER=	tg@FreeBSD.org

BUILD_DEPENDS=	${NUMPYDIR}/Numeric.py:${PORTSDIR}/math/numpy
LIB_DEPENDS=	netcdf.1:${PORTSDIR}/math/netcdf
RUN_DEPENDS=	${NUMPYDIR}/Numeric.py:${PORTSDIR}/math/numpy

USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/Src
CONFIGURE_ENV=	PYTHON=${PYTHON_CMD}

NUMPYDIR=	${PYTHON_SITELIBDIR}/Numeric
SCIENTIFICDIR=	${PYTHON_SITELIBDIR}/Scientific
DOCDIR=		${PREFIX}/share/doc/py-scientific
EXAMPLEDIR=	${PREFIX}/share/examples/py-scientific

post-extract:
	@${SED} -e "s/%%PYTHON_VERSION%%/${PYTHON_VERSION}/g" \
		< ${FILESDIR}/Setup > ${WRKSRC}/Setup
	@${CP} ${PYTHON_LIBDIR}/config/Makefile.pre.in ${WRKSRC}

do-configure:
	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${MAKE} -f Makefile.pre.in boot)

post-install:
	cd ${WRKDIR}/${DISTNAME}; tar cf - Scientific | \
	    (cd ${PYTHON_SITELIBDIR}; tar xf -)
	@${PREFIX}/bin/python ${PYTHON_LIBDIR}/compileall.py ${SCIENTIFICDIR}
	@${PREFIX}/bin/python -O ${PYTHON_LIBDIR}/compileall.py ${SCIENTIFICDIR}
	@${MKDIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/Examples/* ${EXAMPLEDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	cd ${WRKDIR}/${DISTNAME}/Doc; tar cf - . | \
	    (cd ${DOCDIR}; tar xf -)
.endif

.include <bsd.port.mk>
