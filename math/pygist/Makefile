# New ports collection makefile for:	pygist
# Version required:	1.5
# Date created:		30 May 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.2 1998/06/03 06:43:41 tg Exp $
#

DISTNAME=	LLNLPython4
PKGNAME=	pygist-1.5
CATEGORIES=	math
MASTER_SITES=	ftp://ftp-icf.llnl.gov/pub/python/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tg@FreeBSD.ORG

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python \
		${PREFIX}/lib/yorick/1.4/lib/libgist.a:${PORTSDIR}/lang/yorick \
		${SITEPYDIR}/Numeric.py:${PORTSDIR}/math/numpy
RUN_DEPENDS=	python:${PORTSDIR}/lang/python \
		${SITEPYDIR}/Numeric.py:${PORTSDIR}/math/numpy

WRKSRC=		${WRKDIR}/LLNLPython4/Graphics
CONFIGURE_ENV=	PREFIX=${PREFIX}
ALL_TARGET=	sharedmods
MAKE_FLAGS+=	'OPT=${CFLAGS}'

PYTHONSCRIPTDIR=	${PREFIX}/lib/python1.5
SITEPYDIR=	${PREFIX}/lib/python1.5/site-packages
EXAMPLEDIR=	${PREFIX}/share/examples/PyGist

do-configure:
	@(cd ${WRKSRC} && ${CONFIGURE_ENV} python makethis.py)

post-install:
	${INSTALL_DATA} ${WRKSRC}/*/Lib/* ${SITEPYDIR}
	@${PREFIX}/bin/python -O ${PYTHONSCRIPTDIR}/compileall.py ${SITEPYDIR}
	${MKDIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/*/Demo/* ${EXAMPLEDIR}

.include <bsd.port.mk>
