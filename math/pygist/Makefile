# New ports collection makefile for:	pygist
# Date created:		30 May 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gist
PORTVERSION=	1.5
CATEGORIES=	math python
MASTER_SITES=	ftp://ftp-icf.llnl.gov/pub/python/
PKGNAMEPREFIX=	py-
DISTNAME=	LLNLDistribution11
EXTRACT_SUFX=	.tgz

MAINTAINER=	tg@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/yorick/1.4/lib/libgist.a:${PORTSDIR}/lang/yorick \
		${NUMPYDIR}/Numeric.py:${PORTSDIR}/math/numpy \
		${RNGDIR}/RNG.so:${PORTSDIR}/math/numpy
RUN_DEPENDS=	${NUMPYDIR}/Numeric.py:${PORTSDIR}/math/numpy \
		${RNGDIR}/RNG.so:${PORTSDIR}/math/numpy

WRKSRC=		${WRKDIR}/${DISTNAME}/Graphics
USE_PYTHON=	yes
CONFIGURE_ENV=	PREFIX=${PREFIX} PYTHON=${PYTHON_CMD}
ALL_TARGET=	sharedmods
MAKE_FLAGS=	'OPT=${CFLAGS}'

GISTDIR=	${PYTHON_SITELIBDIR}/PyGist
NUMPYDIR=	${PYTHON_SITELIBDIR}/Numeric
RNGDIR=		${PYTHON_SITELIBDIR}/RNG
EXAMPLEDIR=	${PREFIX}/share/examples/PyGist

post-patch:
.for file in Gist3D/Demo/demo5.py Gist3D/Demo/gistmeshtest.py \
		Narcisse/Demo/meshtest.py OOG/Demo/eztest.py \
		OOG/Demo/surftest3d.py OOG/Demo/surftest4d.py
	@${PERL} -pi -e 's/from Ranf import/from RNG import/' ${WRKSRC}/${file}
.endfor

do-configure:
	@(cd ${WRKSRC} && ${CONFIGURE_ENV} ${PYTHON_CMD} makethis.py)

post-install:
	@${MKDIR} ${GISTDIR}
	${INSTALL_DATA} ${WRKSRC}/*/Lib/* ${GISTDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${GISTDIR}
	@${ECHO} "PyGist" > ${GISTDIR}/../PyGist.pth
	${MKDIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/*/Demo/* ${EXAMPLEDIR}

.include <bsd.port.mk>
