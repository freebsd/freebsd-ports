# New ports collection makefile for:	py-martel
# Date created:		19 October 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	martel
PORTVERSION=	0.4
PORTEPOCH=	1
CATEGORIES=	textproc biology python
MASTER_SITES=	http://www.biopython.org/~dalke/Martel/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Martel-0.4

MAINTAINER=	johann@egenetics.com

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/TextTools/__init__.py:${PORTSDIR}/textproc/py-mxTextTools

PYTHON_VERSION=	python2.0

MARTEL_DIR=	${PYTHON_SITELIBDIR}/Martel
MARTEL_EXAMPLEDIR=${PREFIX}/share/examples/martel
MARTEL_DOCDIR=	${PREFIX}/share/doc/martel

do-build:
	@ ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@ ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@ ${MKDIR} ${MARTEL_DIR}
	@ (cd ${WRKSRC} && find *.py *.pyc *.pyo formats test \
	  | cpio --quiet -pdum -R ${BINOWN}:${BINGRP} ${MARTEL_DIR})
	@ ${MKDIR} ${MARTEL_EXAMPLEDIR}/builders
	@ ${INSTALL_DATA} ${WRKSRC}/examples/* ${MARTEL_EXAMPLEDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/builders/* ${MARTEL_EXAMPLEDIR}/builders

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${MARTEL_DOCDIR}
.for docfile in README HISTORY doc/*
	@ ${INSTALL_MAN} ${WRKSRC}/${docfile} ${MARTEL_DOCDIR}
.endfor
.endif

.include <bsd.port.mk>
