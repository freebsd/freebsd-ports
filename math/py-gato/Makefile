# New ports collection makefile for:	py-gato
# Date created:		31 August 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gato
PORTVERSION=	0.98.J
CATEGORIES=	math python
MASTER_SITES=	http://www.zpr.uni-koeln.de/~gato/Download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Gato-${PORTVERSION:U:C|\.([^.]*)$|\1|}
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Python-based toolbox to visualise algorithms on graphs

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/Gato
GATO_DIR=	${PREFIX}/lib/${PYTHON_VERSION}/site-packages/Gato
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}
CPIO=		cpio --quiet -pdum -R

pre-build:
	@ ${TOUCH} ${WRKSRC}/__init__.py

do-build:
	@ ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@ ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@ ${MKDIR} ${GATO_DIR}
	@ cd ${WRKSRC} && ${FIND} *.py *.pyc *.pyo \
	  -name Gato.py\* -o -name Gred.py\* -o -print \
	  | ${CPIO} ${BINOWN}:${BINGRP} ${GATO_DIR}
.for script in Gato Gred
	@ ${INSTALL_SCRIPT} ${WRKSRC}/${script}.py ${PREFIX}/bin/${script}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${EXAMPLESDIR}
.for egfile in *.alg *.pro *.cat
	@ ${INSTALL_DATA} ${WRKSRC}/${egfile} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
