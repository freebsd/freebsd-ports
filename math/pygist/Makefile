# New ports collection makefile for:	pygist
# Version required:	1.5
# Date created:		30 May 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.6 1998/09/01 07:05:05 tg Exp $
#

DISTNAME=	LLNLPython6
PKGNAME=	py-gist-1.5
CATEGORIES=	math python
MASTER_SITES=	ftp://ftp-icf.llnl.gov/pub/python/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tg@FreeBSD.ORG

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python \
		${PREFIX}/lib/yorick/1.4/lib/libgist.a:${PORTSDIR}/lang/yorick \
		${SITEPYDIR}/Numeric.py:${PORTSDIR}/math/numpy \
		${SITEPYDIR}/Ranf.py:${PORTSDIR}/math/rng
RUN_DEPENDS=	python:${PORTSDIR}/lang/python \
		${SITEPYDIR}/Numeric.py:${PORTSDIR}/math/numpy \
		${SITEPYDIR}/Ranf.py:${PORTSDIR}/math/rng

WRKSRC=		${WRKDIR}/${DISTNAME}/Graphics
CONFIGURE_ENV=	PREFIX=${PREFIX}
ALL_TARGET=	sharedmods
MAKE_FLAGS+=	'OPT=${CFLAGS}'

PYTHONSCRIPTDIR=	${PREFIX}/lib/python1.5
SITEPYDIR=	${PYTHONSCRIPTDIR}/site-packages
EXAMPLEDIR=	${PREFIX}/share/examples/PyGist

do-configure:
	@(cd ${WRKSRC} && ${CONFIGURE_ENV} python makethis.py)

post-install:
	${INSTALL_DATA} ${WRKSRC}/*/Lib/* ${SITEPYDIR}
	@${PREFIX}/bin/python -O ${PYTHONSCRIPTDIR}/compileall.py ${SITEPYDIR}
	${MKDIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/*/Demo/* ${EXAMPLEDIR}

.include <bsd.port.mk>
