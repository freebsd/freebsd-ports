# New ports collection makefile for:	numpy
# Version required:	1.0b3
# Date created:		20 April 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.3 1997/05/14 07:38:50 tg Exp $
#

DISTNAME=	NumPy
PKGNAME=	numpy-1.0b3
CATEGORIES=	math
MASTER_SITES=	http://www.sls.lcs.mit.edu/~jjh/numpy/
DISTFILES=	NumPy-1.0b3.tar.gz NumPyLib-1.0b2.tar.gz

MAINTAINER=	tg@FreeBSD.ORG

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
RUN_DEPENDS=	python:${PORTSDIR}/lang/python
LIB_DEPENDS=	lapack\\.2\\.:${PORTSDIR}/math/lapack \
		ranlib\\.1\\.:${PORTSDIR}/math/libranlib

BROKEN=		python upgrade

ALL_TARGET=	sharedmods
MAKE_FLAGS+=	'OPT=${CFLAGS}'

PYTHONSCRIPTDIR=	${PREFIX}/share/python1.4
PYTHONLIBDIR=	${PREFIX}/lib/python1.4/sharedmodules
NUMPYDIR=	${PYTHONSCRIPTDIR}/${DISTNAME}
DOCDIR=		${PREFIX}/share/doc/${DISTNAME}

do-configure:
	@cd ${WRKSRC}; ${MAKE} -f Makefile.pre.in Makefile

do-install:
	@${MKDIR} ${NUMPYDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.so ${PYTHONLIBDIR}
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}/*.py ${NUMPYDIR}
	@PYTHONPATH=${PYTHONSCRIPTDIR}:${NUMPYDIR} \
		${PREFIX}/bin/python ${PYTHONSCRIPTDIR}/compileall.py ${NUMPYDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/html/*.html ${DOCDIR}
.endif

.include <bsd.port.mk>
