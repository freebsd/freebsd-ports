# New ports collection makefile for:	py-martel
# Date created:		19 October 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	martel
PORTVERSION=	0.6
PORTEPOCH=	1
CATEGORIES=	textproc biology python
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	wjv
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Martel-${PORTVERSION}

MAINTAINER=	wjv@FreeBSD.org

BUILD_DEPENDS=	${PYDISTUTILS}
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/mx/TextTools/__init__.py:${PORTSDIR}/lang/py-mx-base

USE_PYTHON=	yes
USE_BZIP2=	yes
PYTHON_SETUP=	${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}

do-build:
	@ cd ${WRKSRC} && ${PYTHON_SETUP} build

pre-install:
	@ ${SH} ${PKGREQ} INSTALL

do-install:
	@ cd ${WRKSRC} && ${PYTHON_SETUP} install -c -O1 --prefix=${PREFIX}

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for docfile in README HISTORY doc/*
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
	@ ${MKDIR} ${EXAMPLESDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
