# New ports collection makefile for:	pygist
# Version required:	1.5
# Date created:		30 May 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.8 1998/11/16 08:54:41 tg Exp $
#

DISTNAME=	LLNLPython8
PKGNAME=	py-gist-1.5
CATEGORIES=	math python
MASTER_SITES=	ftp://ftp-icf.llnl.gov/pub/python/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tg@FreeBSD.ORG

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python \
		${PREFIX}/lib/yorick/1.4/lib/libgist.a:${PORTSDIR}/lang/yorick \
		${NUMPYDIR}/Numeric.py:${PORTSDIR}/math/numpy \
		${RNGDIR}/Ranf.py:${PORTSDIR}/math/rng
RUN_DEPENDS=	python:${PORTSDIR}/lang/python \
		${NUMPYDIR}/Numeric.py:${PORTSDIR}/math/numpy \
		${RNGDIR}/Ranf.py:${PORTSDIR}/math/rng

WRKSRC=		${WRKDIR}/${DISTNAME}/Graphics
CONFIGURE_ENV=	PREFIX=${PREFIX}
ALL_TARGET=	sharedmods
MAKE_FLAGS+=	'OPT=${CFLAGS}'

PYTHONSCRIPTDIR=	${PREFIX}/lib/python1.5
GISTDIR=	${PYTHONSCRIPTDIR}/site-packages/PyGist
NUMPYDIR=	${PYTHONSCRIPTDIR}/site-packages/NumPy
RNGDIR=		${PYTHONSCRIPTDIR}/site-packages/RNG
EXAMPLEDIR=	${PREFIX}/share/examples/PyGist

do-configure:
	@(cd ${WRKSRC} && ${CONFIGURE_ENV} python makethis.py)

post-install:
	@${MKDIR} ${GISTDIR}
	${INSTALL_DATA} ${WRKSRC}/*/Lib/* ${GISTDIR}
	@${PREFIX}/bin/python -O ${PYTHONSCRIPTDIR}/compileall.py ${GISTDIR}
	@${ECHO} "PyGist" > ${GISTDIR}/../PyGist.pth
	${MKDIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/*/Demo/* ${EXAMPLEDIR}

.include <bsd.port.mk>
