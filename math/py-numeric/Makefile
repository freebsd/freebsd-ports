# New ports collection makefile for:	numpy
# Version required:	1.0b3
# Date created:		20 April 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id$
#

DISTNAME=	NumPy
PKGNAME=	numpy-1.0b3
CATEGORIES=	math
MASTER_SITES=	http://www.sls.lcs.mit.edu/~jjh/numpy/
DISTFILES=	NumPy-1.0b3.tar.gz NumPyLib-1.0b2.tar.gz

MAINTAINER=	tg@FreeBSD.ORG

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
LIB_DEPENDS=	lapack\\.2\\.:${PORTSDIR}/math/lapack \
		ranlib\\.1\\.:${PORTSDIR}/math/libranlib

ALL_TARGET=	sharedmods
MAKE_FLAGS+=	'OPT=${CFLAGS}'

PYTHONDIR=	${PREFIX}/share/python1.4
NUMPYDIR=	${PYTHONDIR}/${DISTNAME}
DOCDIR=		${PREFIX}/share/doc/${DISTNAME}

do-configure:
	@cd ${WRKSRC}; ${MAKE} -f Makefile.pre.in Makefile

do-install:
	@${MKDIR} ${NUMPYDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.so ${NUMPYDIR}
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}/*.py ${NUMPYDIR}
	@PYTHONPATH=${PYTHONDIR}:${NUMPYDIR} \
		${PREFIX}/bin/python ${PYTHONDIR}/compileall.py ${NUMPYDIR}
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/html/*.html ${DOCDIR}

.include <bsd.port.mk>
