# New ports collection makefile for:	py-martel
# Date created:		19 October 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	martel
PORTVERSION=	0.5
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	textproc biology python
MASTER_SITES=	http://www.biopython.org/~dalke/Martel/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Martel-${PORTVERSION}

MAINTAINER=	johann@egenetics.com

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/TextTools/__init__.py:${PORTSDIR}/textproc/py-mxTextTools

PYTHON_VERSION=	python2.0
PLIST=		${WRKDIR}/PLIST
PKG_PLIST=	${PKGDIR}/pkg-plist

MARTEL_DIR=	${PYTHON_SITELIBDIR}/Martel
MARTEL_EGDIR=	${PREFIX}/share/examples/martel
MARTEL_DOCDIR=	${PREFIX}/share/doc/martel
MARTEL_DOCS=	README HISTORY doc/intro.txt doc/tech_description.txt \
		doc/writing_a_format.txt

do-build:
	@ ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@ ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

pre-install:
	@ ${CAT} ${PKG_PLIST} > ${PLIST}
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${MARTEL_DOCDIR}
.for docfile in ${MARTEL_DOCS}
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${MARTEL_DOCDIR}/ && \
	  ${ECHO} ${MARTEL_DOCDIR:S|^${PREFIX}/||}/${docfile:S|^doc/||} \
	  >> ${PLIST}
.endfor
	@ ${ECHO} @dirrm ${MARTEL_DOCDIR:S|^${PREFIX}/||} >> ${PLIST}
.endif

do-install:
	@ ${MKDIR} ${MARTEL_DIR}
	@ (cd ${WRKSRC} && find *.py *.pyc *.pyo formats test \
	  | cpio --quiet -pdum -R ${BINOWN}:${BINGRP} ${MARTEL_DIR})
	@ ${MKDIR} ${MARTEL_EGDIR}/builders
	@ ${INSTALL_DATA} ${WRKSRC}/examples/* ${MARTEL_EGDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/builders/* ${MARTEL_EGDIR}/builders

.include <bsd.port.mk>
